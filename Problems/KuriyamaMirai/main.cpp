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

#define maxN 100000
#define logMaxN 20

ll N, a[maxN], b[maxN];
ll segmentTree[3 * maxN], ss;
ll sortedSegmentTree[3 * maxN];

void precalcSegmentTree(ll N) {
	// Reseteamos los valores y ponemos cosas ignorables
	memset(segmentTree, 0, sizeof(segmentTree));
	memset(sortedSegmentTree, 0, sizeof(sortedSegmentTree));

	FOR(i, 0, ss) {
		segmentTree[ss + i] = 0;
		sortedSegmentTree[ss + i] = 0;
	}
	// almacenamos las hojas
	FOR(i, 0, N) {
		segmentTree[ss + i] = a[i];
		sortedSegmentTree[ss + i] = b[i];
	}

	// Precalcular el resto del arbol
	for (ll i = ss - 1; i; i--) {
		// Recordar que i<<1 == 2*i y 1<<1|1 == 2*1+1
		// segmentTree[i] = segmentTree[2 * i] + segmentTree[2 * i + 1];
		segmentTree[i] = segmentTree[i << 1] + segmentTree[i << 1 | 1];
		sortedSegmentTree[i] = sortedSegmentTree[i << 1] + sortedSegmentTree[i << 1 | 1];
	}
}

ll query1(int n, int l, int r, int d) { // [l,r]
	// Opcion 2 el rango no es contenido
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

ll query2(int n, int l, int r, int d) { // [l,r]
	// Opcion 2 el rango no es contenido
	if (l > r) return 0;
	// Opcion 1 porque l vale 0 y r vale d-1
	// el rango es: [0,d)
	if (!l && r == d - 1) {
		return sortedSegmentTree[n];
	}
	// Opcion 3: Notar que si el rango no contiene al hijo izquierdo l sera mayor a r y si no contiene al hijo derecho r sera menor a l
	d /= 2;
	return query2(n << 1, l, min(d - 1, r), d) + query2(2 * n + 1, max(0, l - d), r - d, d);
}

int main(int argc, char const *argv[])
{
	ll n;
	cin >> n;
	FOR(i, 0, n) {
		cin >> a[i];
		b[i] = a[i];
	}
	sort(b, b + n);
	ss = 1 << (ll)ceil(log2(n));
	precalcSegmentTree(n);
	int Q, l, r, t;
	ll x;
	cin >> Q; // Cantidad de queries
	FOR(i, 0, Q) {
		cin >> t >> l >> r;
		l--;
		r--;

		if (t == 1) {
			x = query1(1, l, r, ss);
			cout << x << endl;
		}
		if (t == 2) {
			x = query2(1, l, r, ss);
			cout << x << endl;
		}
	}
	return 0;
}