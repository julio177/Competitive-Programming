// Tipos de query:
// Tipo 1) obtener algun valor (suma, alguna funcion, etc.) en el Rango [l,r]
// Tipo 2) Modificacion de 1 elemento=> i,x
// Tipo 3) Modificacion de rango de elementos [l,r]

#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <queue>
#include <map>
#include <numeric>
#include <set>
#include <sstream>
#include <stack>
#include <utility>
#include <vector>

#define INF 1000000000
#define FOR(i, a, b) for(int i=int(a); i<int(b); i++)
#define FORC(cont, it) for(decltype((cont).begin()) it = (cont).begin(); it != (cont).end(); it++)
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;

// Hay varias maneras de obtener respuestas en rangos, todas involucran precalcular algo, ya que sin esto no podemos responder rapidamente
// Naive: iterar sobre el rango [l,r] O(N) por query
// Partial sums: precalc O(N), query: O(1)
// Sparse table precalc: O(NlogN), query: usualmente O(1)
// Segment Tree precalc: O(N), query: O(logN)

#define maxN 1000000
#define logMaxN 20

// En una sparse table se guarda la respuesta para un rango con tamaño una potencia de 2, empezando desde el indice j
// sparse[i][j] => contiene la respuesta para el rango [j,j+2^i)
// Hay 2 maneras de responder las queries usando sparse table:
// 1) Partir el numero en binario e ir obteniendo las respuestas de acuerdo a eso O(logN)
// 2) Obtener la k mas grande tal que 2^k sea menor al tamaño del rango, agarrar obtener la respuesta de los rangos [l,l+2^K) y [r-2^k+1, r]
// Notar que ambos rangos se van a intersectar, por ende este solo sirve si hablamos de minimos o maximos en un rango. O(1)
// Solo permite queries tipo 1
// Sparse table no es muy util ya que un segment tree hace lo mismo y a menos que sean muchas queries no se nota la diferencia.
// Lo importante es la idea de precalcular en potencias de 2.
// Memoria: O(NlogN)
int sparse[logMaxN][maxN];

void precalcSparse(int N) {
	// Notar que sparse[0][j] guarda el valor que tenemos en la posicion j del arreglo original
	FOR(i, 1, logMaxN) {
		FOR(j, 0, N) {
			// notar que la segunda parte del max puede exceder maxN, se puede lidiar con una condicion o solo haciendo maxN el doble de lo que esperamos que sea maxN
			sparse[i][j] = max(sparse[i - 1][j], sparse[i - 1][j + (1 << (i - 1))]);
			// Usualmente uso la condicion y se ve algo asi:
			sparse[i][j] = sparse[i - 1][j];
			int nextJ = j + (1 << (i - 1));
			if (nextJ < N) sparse[i][j] = max(sparse[i][j], sparse[i - 1][nextJ]);
		}
	}
}

// Sumas parciales
// s[i] -> La suma desde el inicio hasta la posicion i
// Para responder una query del rango [l,r] la respuesta es s[r]-s[l-1], O(1)
// Se pueden hacer mas cosas que sumas, siempre y cuando la operacion sea reversible, por ejemplo suma se revierte con resta, multiplicacion con division, etc.
// Obtener el minimo/maximo no es reversible, por ende no funciona partial sums
// Solo permite queries tipo 1
// Memoria: O(N)
int N, a[maxN], s[maxN];

void precalcPartialSums(int N) {
	// Notar que para partial sums a mi me gusta que s[0] sea 0 y s[1] tenga el primer valor, etc.
	// Este padding hace que si nos pidieran el rango [0,r], al hacer s[0-1] nos salimos del arreglo
	// Por supuesto que con el padding tenemos que responder s[r+1]-s[l]
	FOR(i, 1, N+1) {
		s[i] = s[i - 1] + a[i - 1];
	}
}

// Potencial nodo para un segment tree, no lo recomiendo porque se vuelve mas tedioso de implementar, recomiendo usar la otra
struct Node {
	Node * left, * right;
	int value;
};

// Existen casos en los que cada nodo del segment tree guarda mas de 1 valor, para este tipo de casos podemos usar una estructura algo asi:
// Recordar que si usamos la logica de que los hijos del nodo i se encuentran en 2*i y 2*i+1 no necesitamos apuntadores a los hijos.
struct Node2 {
	// Incluso podemos meter lazy aqui, y tambien pueden haber varias variables para lazy!!
	int v1, v2, v3; // v4,v5...
};

// Segment tree puede manejar por si solo queries tipo 1 y 2, con lazy propagation puede manejar queries tipo 3
// El nodo i guarda la respuesta para todo el rango de las hojas del subarbol con raiz en i (otra manera de decirlo es la respueta del rango que contiene)
// Puede llegar a usar hasta 4*N de memoria, por los paddings para completar la potencia de 2 y el doble de eso por los padres.
int segmentTree[3 * maxN], lazy[3 * maxN], ss;

// O(N)
// Iteramos sobre las hojas y establecemos sus valores
// De ahi iteramos sobre los nodos que quedan, del de mayor indice al de menor indice
void precalcSegmentTree(int N) {
	// Reseteamos los valores y ponemos cosas ignorables
	memset(lazy, 0, sizeof(lazy));
	FOR(i, 0, ss) segmentTree[ss + i] = 0;
	// almacenamos las hojas
	FOR(i, 0, N) {
		segmentTree[ss + i] = a[i];
	}

	// Precalcular el resto del arbol
	for (int i = ss - 1; i; i--) {
		// Recordar que i<<1 == 2*i y 1<<1|1 == 2*1+1
		// segmentTree[i] = segmentTree[2 * i] + segmentTree[2 * i + 1];
		segmentTree[i] = segmentTree[i << 1] + segmentTree[i << 1 | 1];
	}
}

// Metodo para propagar de manera lazy en un arbol
void propagate(int n, int d) {
	if (lazy[n]) {
		segmentTree[n] += lazy[n] * d;
		if (n<ss) {
			lazy[n << 1] += lazy[n];
			lazy[n << 1 | 1] += lazy[n];
		}
		lazy[n] = 0;
	}
}

// Metodo recursivo para responder queries tipo 1
// Al recorrer un segment tree:
// Opcion 1) El rango contiene el valor que el nodo precalcula completamente (regresamos el valor del nodo)
// Opcion 2) El rango no es contenido por el nodo (regresamos algo ignorable)
// Opcion 3) El rango es contenido parcialmente por el nodo (vistamos los 2 hijos)
// O(logN)
int query(int n, int l, int r, int d) { // [l,r]
	// solo ocupamos el metodo propagate si hay queries tipo 3
	propagate(n, d);
	// Opcion 2 el rango no es contenido
	if (l > r) return 0;
	// Opcion 1 porque l vale 0 y r vale d-1
	// el rango es: [0,d)
	if (!l && r == d - 1) {
		return segmentTree[n];
	}
	// Opcion 3: Notar que si el rango no contiene al hijo izquierdo l sera mayor a r y si no contiene al hijo derecho r sera menor a l
	d /= 2;
	return query(n << 1, l, min(d-1, r), d) +
		query(2 * n + 1, max(0, l - d), r - d, d);
}

// Query tipo 2
// log(N)
// En este caso estamos modificando el valor a x, tambien se puede modificar (sumar, restar, multiplicar, etc.) en x
void modify(int n, int x) {
	segmentTree[n] = x;
	while (n >>= 1) {
		segmentTree[n] = segmentTree[n << 1] + segmentTree[n << 1 | 1];
	}
}

// Query tipo 3 con lazy propagation
// Para este caso en particular le vamos a sumar x a todo el intervalo [l,r], tambien se puede cambiar el intervalo [l,r] a que valga x
void query3(int n, int l, int r, int d, int x) {
	propagate(n, d);
	// Opcion 2 el rango no es contenido
	if (l > r) return;
	// Opcion 1 porque l vale 0 y r vale d-1
	// [0,d)
	if (!l && r == d - 1) {
		lazy[n] += x;
		propagate(n, d);
		return;
	}
	// Opcion 3
	d /= 2;
	query3(n << 1, l, min(d - 1, r), d, x);
	query3(2 * n + 1, max(0, l - d), r - d, d, x);
	// Reestablecemos los valores de este nodo porque cambiamos el valor de al menos a 1 de sus hijos 
	segmentTree[n] = segmentTree[n << 1] + segmentTree[n << 1 | 1];
}

int main() {
	while (cin >> N) {
		FOR(i, 0, N) {
			cin >> a[i];
		}
		// Recordar que necesitamos un padding para que la primera hoja empiece en potencia de 2
		ss = 1 << (int)ceil(log2(N));
		precalcSegmentTree(N);
		int Q, l, r, t, x;
		cin >> Q; // Cantidad de queries
		FOR(i, 0, Q) {
			cin >> t >> l >> r;
			if (t == 1) {
				cout << query(1, l, r, ss) << endl;
			}
			else if (t==2) {
				// Recordar que si tenemos queries tipo 2 y 3 no debemos mezclarlas, convertimos la tipo 2 en tipo 3
				// Esta linea tiene un bug, cual, porque y como corregirlo?
				query3(1, l, l, ss, r-segmentTree[ss+l]);
			}
			else if (t == 3) {
				cin >> x;
				query3(1, l, r, ss, x);
			}
		}
	}
	return 0;
}

// Notas extra: 

// Segment tree permite hacer cosas super cool como busqueda binaria en los nodos y dependiendo de la respueta del hijo es si se mueve al hijo izquierdo o derecho
// Para muchos problemas se pueden sortear los numeros y luego aplicar coordinate compression y meterlos en un segment tree y hacer preguntas sobre ellos.
// Un ejemplo simple de esto es para cada nodo, cuantos numeros existen que se encuentran a su izquierda y son mayores a el. 

// Por ejemplo, para el input:
// 5 4 3 2 1
// La respuesta seria
// 0 1 2 3 4

// Como mencione el problema se puede resolver con un segment tree al sortearlos y luego aplicar coordinate compression
// No hay que temer coordinate compression, es bastante simple:
// Basicamente es guardar los numeros originales y una version sorteada de ellos y luego para cada numero encontrar su posicion en la lista de elementos sorteados, dicha posicion corresponde al indice de la hoja del arbol
// Para cada numero del arreglo original se lanza la query desde 0 hasta la posicion del numero - 1
// Y despues en la hoja que corresponde al numero que se esta procesando se le incrementa el valor en 1 

// La propiedad de la busqueda binaria se podria aplicar si en vez de eso nos dieran una query: i k
// Que implica que si los numeros en el rango [0,i] estuviesen sorteados de menor a mayor, cual seria el numero en la posicion k
// Misma idea del problema pasado (sortear y coordinate compression) y cada nodo tiene guardados cuantos existen abajo de el
// Entonces, si el hijo izquierdo tiene un numero menor a K nos movemos a el y si es mayor le restamos dicho numero a K y nos movemos al derecho.
// Este problema es mas avanzado y requiere offline queries (offline implica que no hay modificacion, osea solo tipo 1)
// Notar que las queries pueden ir en cualqueir orden, asi que necesitamos sortearlas
// Ya que son offline no importa el orden en que las respondemos, lo que si importa es como las imprimimos, para eso necesitamos guardar sus indices

// Existen segment trees de multiples dimensiones, por ejemplo en un 2D cada nodo guarda un segment tree de 1 dimension

// Existe una version iterativa de segment trees: http://codeforces.com/blog/entry/18051?
// No recomiendo intentar entender la iterativa si no se entiende la recursiva primero, ya que la iterativa se basa en muchos disjoint segment trees y por ende no necesita padding.
// Mas rapida que recursiva, aunque pierde la propiedad que nos permite realizar busquedas binarias si N no es potencia de 2 (por que son muchos segment trees y no solo 1)

// Esta funcion solo funciona si se responden solamente queries de tipo 1 y 2, para queries tipo 3 recomiendo usar la recursiva, aunque tambien existe una iterativa, la pueden leer en el sitio.
int iterativeQuery(int l, int r) { // Da la respuesta para el rango [l,r)
	int sum = 0;
	for (l += N, r += N; l < r; l >>= 1, r >>= 1) {
		if (l & 1) sum += segmentTree[l++];
		if (r & 1) sum += segmentTree[--r];
	}
	return sum;
}

// Fenwick vs Segment tree:
// + Fenwick es mas rapido que la implementacion recursiva de segment tree porque es iterativo (es basicamente igual de rapido que la iterativa)
// + Fenwick son menos lineas (approx 1 linea menos :v)
// + Fenwick usa exactamente N de memoria (no deberia hacer diferencia con respecto al 2*N de segment tree iterativo)
// --- Fenwick necesita operaciones reversibles.
// --- Todo lo que se resuelve con fenwick
// --- se puede hacer con segment tree pero no alrevez. (desventaja tan grande que vale por 9)
// Es evidente que la desventaja de fenwick vs segment tree es muy fuerte y por ende segment tree es superior
// Los fieles seguidores de fenwick tree diran que es mas rapido pero es porque no conocen la implementacion iterativa de segment tree
// Fenwick no permite hacer la busqueda binaria entre los nodos