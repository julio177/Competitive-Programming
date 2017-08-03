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

#define maxN 1000000
#define logMaxN 20

ll N, a[maxN], lazy[3 * maxN];
ll segmentTree[3 * maxN], ss;

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

void precalcSegmentTree(ll N) {
	memset(lazy, 0, sizeof(lazy));

	FOR(i, 0, ss) {
		segmentTree[ss + i] = 0;
	}
	// almacenamos las hojas
	FOR(i, 0, N) {
		segmentTree[ss + i] = a[i];
	}

	// Precalcular el resto del arbol
	for (ll i = ss - 1; i; i--) {
		// Recordar que i<<1 == 2*i y 1<<1|1 == 2*1+1
		// segmentTree[i] = segmentTree[2 * i] + segmentTree[2 * i + 1];
		segmentTree[i] = segmentTree[i << 1] + segmentTree[i << 1 | 1];
	}
}

ll query1(int n, int l, int r, int d) { // [l,r]
	// Opcion 2 el rango no es contenido
	propagate(n, d);

	if (l > r) return 0;
	// Opcion 1 porque l vale 0 y r vale d-1
	// el rango es: [0,d)
	if (!l && r == d - 1) {
		return segmentTree[n];
	}
	// Opcion 3: Notar que si el rango no contiene al hijo izquierdo l sera mayor a r y si no contiene al hijo derecho r sera menor a l
	d /= 2;
	return query1(n << 1, l, min(d - 1, r), d) + query1(2 * n + 1, max(0, l - d), r - d, d);
}

int main(int argc, char const *argv[])
{
	int n, M, L;
	int Q, l, r, t;

	memset(a, 0, sizeof(a));

	cin >> n >> M >> L;
	ss = 1 << (int)ceil(log2(L));
	precalcSegmentTree(L);

	FOR(i, 0, n) {
		cin >> l >> r;
		query3(1, l, r, ss, 1);
	}

	FOR(i, 0, M) {
		cin >> t;
		cout << query1(1, t, t, ss) << endl;
	}
	return 0;
}