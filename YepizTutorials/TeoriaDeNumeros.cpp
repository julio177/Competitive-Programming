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
#define FORC(cont, it) for(typeof((cont).begin()) it = (cont).begin(); it != (cont).end(); it++)
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;

#define maxN 100000000

int pc = 0, f[maxN], primes[maxN / 10];

int main() {
	// Extra información de teoría de números : Precalcular cosas interesantes usando modificaciones al Sieve of Eratosthenes

	// Primero hay que notar una propiedad del Sieve de Eratosthenes clasico O(NlogN) 
	// Visitamos a cada numero la cantidad de divisors que tiene - 2 (el numero tal cual y 1), y no solo eso cada vez que lo visitamos es con uno de sus divisores
	// Supongamos que nos piden cuantos divisors tiene un número y habrán muchas queries, se puede precalcular con el siguiente codigo
	// Notar que es una modificación del Sieve of Eratostenes en O(NlogN), esta vez se incluyen el 1 y el numero tal cual
	// Si en vez de eso quisieramos la suma de todos sus divisores hariamos countDivs[j]+=i;
	// En fin, aqui lo importante no es memorizar las variaciones, sino entender lo que hace el sieve clasico y por ende como modificarlo para lograr cosas interesantes.
	// De igual manera notar que si un numero tiene 2 divisores implica que es primo, que otras propiedades/modificaciones se te ocurren se pueden obtener en base a esto??
	// Problema reto 1: Precalcula todos los divisores de cada numero menor a N en tiempo NlogN
	const int N = 1000;
	int countDivs[N];
	vi divisors[N];
	memset(countDivs, 0, sizeof(countDivs));
	FOR(i, 1, N) {
		for (int j = i; j < N; j += i) countDivs[j]++;
	}

	// Modificacion del Sieve de Eratosthenes optimizado O(NloglogN)
	// Cuantos divisores primos tiene un numero?
	// Notar que el sieve optimizado visita a cada numero la cantidad de primos que tiene, ya que el segundo for solo lo vamos a correr si el numero es primo
	// Tambien podemos modificarlo para obtener cosas como el producto de sus primos, o la suma de sus primos, tambien como se menciono en clase el primo mas chico/grande de cada numero
	// Incluso si se ponen creativos se puede modificar un poco mas para lograr cosas como: el primo que mas aparece en cada numero y cuantas veces aparece
	// Por supuesto que para algunas de estas cosas necesitamos arreglos auxiliares, condiciones extras e incluso podemos meter un mas ciclos de por medio (modificar la complejidad de tiempo sin necesariamente hacerlo peor que O(NlogN))
	// Problema reto 2: Precalcula todos los factores primos de todos los numeros menores a N en tiempo NloglogN
	// Problema reto 3: Utiliza y modifica el siguiente sieve para precalcular phi(N) en tiempo NloglogN
	int countPrimes[N], phi[N];
	vi primeFactors[N];
	memset(countPrimes, 0, sizeof(countPrimes));
	FOR(i, 2, N) {
		if (!countPrimes[i]) {
			for (int j = i; j < N; j += i) countPrimes[j]++;
		}
	}

	// Sieve of Eratostenes modificado para correr en tiempo O(N), puede llegar a ser util, aunque en el 99+% de las veces el sieve en NloglogN es mas que suficiente
	// f[i] guarda el primo mas chico que divide a i
	// primes guarda los primos
	// pc tiene la cantidad de primos calculados hasta el momento, por ende cuando termina de ejecutarse pc tiene la cantidad de primos menores a N
	// Problema reto 4 (Avanzado): Entender porque funciona (cuantas veces se visita cada f[i] y de que numero se visita??)
	clock_t t = clock();
	FOR(i, 2, maxN) {
		if (!f[i]) primes[pc++] = i, f[i] = i;
		for (int j = 0; j < pc && 1LL*i*primes[j] < maxN && primes[j] <= f[i]; j++) f[i*primes[j]] = primes[j];
	}
	t = clock() - t;
	// Notar que es tiempo lineal y usualmente toma 1-3 segundos en correr, a pesar de que un procesador puede hacer approximadamente 10^9 operaciones por segundo
	// Esto pasa porque el procesador puede hacer 10^9 operaciones por segundo si estan cacheadas, en otras palabras las variables y arreglos que usa caben dentro de la memoria del procesador
	// En este caso tenemos un arreglo de 10^8, lo cual definitivamente no cabe (en el 2016 1-8MB era el standard, osea 10^6)
	// En otras palabras tenemos que hacer operaciones mas costosas, que son sacar de memoria cache la porcion del arreglo que tenemos para meter la nueva porcion que necesitamos
	// Como experimento: Cambiar el tipo de f y primes al tipo long long, que pasa??
	printf("I discovered that there are %d primes smaller than %d in %f seconds.\n", pc, maxN, ((float)t) / CLOCKS_PER_SEC);

	//Existen muchisisimas variaciones de el Sieve of Eratosthenes, y algunas son muy utiles y otras no tanto, con este documento queria que se familiarizaran con las mas basicas/comunes, ya que los pueden salvar de un apuro porque se codean en approx 5 lineas
	return 0;
}