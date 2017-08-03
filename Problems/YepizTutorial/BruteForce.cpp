// Bruteforce
// Los problemas de bruteforce se tratan de probar todas las posibles combinaciones/permutaciones
// Hay varias variaciones, las mas comunes son:
//   1) Elegir el menor (max,min)
//   2) Obtener al menos 1 manera valida de hacer algo
//   3) Obtener todas las maneras de hacer algo (dados ciertos constraints que no permiten usar DP, etc.)
// Usualmente tienen un orden exponencial o factorial
// Aqui se muestran 2 ejemplos simples de como obtener dichas complejidades y un fibonacci lento
// Obviamente estas funciones son muy lentas, pero para casos en los que se piden hacer cosas que no se pueden optimizar es util conocer como se ven

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

// Regresa n! en tiempo O(n!)
int slowFact(int n) {
	if (!n) return 1;
	int ret = 0;
	FOR(i, 0, n) ret += slowFact(n - 1);
	return ret;
}

// Regresa x^n en tiempo O(x^n)
int slowPow(int x, int n) {
	if (!n) return 1;
	int ret = 0;
	FOR(i, 0, x) ret += slowPow(x, n - 1);
	return ret;
}

// Regresa Fib(n) en tiempo O(Fib(n)), donde Fib(i) es el i-esimo numero de fibonacci
int slowFib(int n) {
	if (n <= 1) return n;
	return slowFib(n - 1) + slowFib(n - 2);
}

int main() {
	// Si la complejidad es n! usualmente n<=10
	FOR(i, 0, 10) {
		cout << slowFact(i) << ' ';
	}
	cout<<endl;
	// Si la complejidad es 2^n usualmente n<=25 (mas comun incluso n=20)
	FOR(i, 0, 10) {
		cout << slowPow(2, i) << ' ';
	}
	cout<<endl;
	FOR(i, 0, 10) {
	    // Que hace la segunda parte de este cout y porque jala??
		cout << slowPow(5, i) << " \n"[i == 9];
	}
	FOR(i, 0, 10) {
		cout << slowFib(i) << " \n"[i == 9];
	}
	return 0;
}
