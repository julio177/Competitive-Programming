#include <bits/stdc++.h>

#define INF 1000000000
#define FOR(i, a, b) for(int i=int(a); i<int(b); i++)
#define FORC(cont, it) for(decltype((cont).begin()) it = (cont).begin(); it != (cont).end(); it++)
#define pb push_back
#define maxN 100000

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<string> vs;
typedef stack<int> si;
typedef vector<ii> vii;
typedef vector<vi> vvi;


ll myMin(ll a, ll b) {
    if (a < b) return a;
    return b;
}

ll myMax(ll a, ll b) {
    if (a > b) return a;
    return b;
}


// Tipos de query:
// Tipo 1) obtener algun valor (suma, alguna funcion, etc.) en el Rango [l,r]
// Tipo 2) Modificacion de 1 elemento=> i,x
// Tipo 3) Modificacion de rango de elementos [l,r]


// Segment tree puede manejar por si solo queries tipo 1 y 2, con lazy propagation puede manejar queries tipo 3
// El nodo i guarda la respuesta para todo el rango de las hojas del subarbol con raiz en i (otra manera de decirlo es la respueta del rango que contiene)
// Puede llegar a usar hasta 4*N de memoria, por los paddings para completar la potencia de 2 y el doble de eso por los padres.
ll segmentTree[3 * maxN], lazy[3 * maxN], ss, a[maxN], N;

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
		// Recordar que i << 1 == 2 * i y 1 << 1 | 1 == 2 * 1 + 1
		// segmentTree[i] = segmentTree[2 * i] + segmentTree[2 * i + 1];
		segmentTree[i] = segmentTree[i << 1] + segmentTree[i << 1 | 1];
	}
}

// Metodo para propagar de manera lazy en un arbol
void propagate(int n, int d) {
	if (lazy[n]) {
        segmentTree[n] = segmentTree[n] ^ lazy[n];
		if (n < ss) {
			cout << "------ before" << endl;
			cout << lazy[n << 1] << endl;
			cout << lazy[n << 1 | 1] << endl;
			cout << "------" << endl;
            lazy[n << 1] += lazy[n];
			lazy[n << 1 | 1] += lazy[n];
			cout << "------ after" << endl;
			cout << lazy[n << 1] << endl;
			cout << lazy[n << 1 | 1] << endl;
			cout << "------" << endl;
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
ll query(ll n, ll l, ll r, ll d) { // [l,r]

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
	return query(n << 1, l, myMin(d - 1, r), d) + query(n << 1 | 1, myMax(0, l - d), r - d, d);
}


// Query tipo 3 con lazy propagation
// Para este caso en particular le vamos a sumar x a todo el intervalo [l,r], tambien se puede cambiar el intervalo [l,r] a que valga x
void query3(ll n, ll l, ll r, ll d, ll x) {
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
	query3(n << 1, l, myMin(d - 1, r), d, x);
	query3(2 * n + 1, myMax(0, l - d), r - d, d, x);
	// Reestablecemos los valores de este nodo porque cambiamos el valor de al menos a 1 de sus hijos
    segmentTree[n] = segmentTree[n << 1] + segmentTree[2 * n + 1];
}

int main() {
    scanf("%I64d", &N);
    FOR(i, 0, N) {
        scanf("%I64d", &a[i]);
    }
    ss = 1 << (ll)ceil(log2(N));
    precalcSegmentTree(N);
    ll Q, l, r, t, val;
    ll x;
    int help = 0;
    scanf("%d", &Q);
    FOR(i, 0, Q) {
        scanf("%d", &t);
        if (t == 1) {
            scanf("%I64d %I64d", &l, &r);
            // Decrement for 0 indexed
            l--; r--;
            cout << query(1, l, r, ss) << endl;
        }
        else {
            scanf("%I64d %I64d %I64d", &l, &r, &val);
            // Decrement for 0 indexed
            l--; r--;
            query3(1, l, r, ss, val);
        }
    }
    return 0;
}