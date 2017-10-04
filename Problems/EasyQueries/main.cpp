#include <bits/stdc++.h>

#define INF 1000000000
#define FOR(i, a, b) for(int i=int(a); i<int(b); i++)
#define RFOR(i, a, b) for(int i=int(a)-1; i>=int(b); i--)
#define FORC(cont, it) for(typeof((cont).begin()) it = (cont).begin(); it != (cont).end(); it++)
#define RFORC(cont, it) for(typeof((cont).rbegin()) it = (cont).rbegin(); it != (cont).rend(); it++)
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

int segmentTree[3 * maxN], lazy[3 * maxN], ss, a[maxN], b[maxN], segmentTree2[3 * maxN], lazy2[3 * maxN];

void precalcSegmentTree(int N) {
	memset(lazy, 0, sizeof(lazy));
	FOR(i, 0, ss) segmentTree[ss + i] = 0;
	FOR(i, 0, N) {
		segmentTree[ss + i] = a[i];
	}

	for (int i = ss - 1; i; i--) {
		segmentTree[i] = segmentTree[i << 1] + segmentTree[i << 1 | 1];
	}
}

void precalcSegmentTree2(int N) {
	memset(lazy2, 0, sizeof(lazy2));
	FOR(i, 0, ss) segmentTree2[ss + i] = 0;
	FOR(i, 0, N) {
		segmentTree2[ss + i] = b[i];
	}

	for (int i = ss - 1; i; i--) {
		segmentTree2[i] = segmentTree2[i << 1] + segmentTree2[i << 1 | 1];
	}
}

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

void propagate2(int n, int d) {
	if (lazy2[n]) {
		segmentTree2[n] += lazy2[n] * d;
		if (n<ss) {
			lazy2[n << 1] += lazy2[n];
			lazy2[n << 1 | 1] += lazy2[n];
		}
		lazy2[n] = 0;
	}
}

int query(int n, int l, int r, int d) { 
	propagate(n, d);
	if (l > r) return 0;
	if (!l && r == d - 1) {
		return segmentTree[n];
	}
	d /= 2;
	return query(n << 1, l, min(d-1, r), d) + query(2 * n + 1, max(0, l - d), r - d, d);
}

int queryB(int n, int l, int r, int d) { 
	propagate2(n, d);
	if (l > r) return 0;
	if (!l && r == d - 1) {
		return segmentTree2[n];
	}
	d /= 2;
	return queryB(n << 1, l, min(d-1, r), d) + queryB(2 * n + 1, max(0, l - d), r - d, d);
}

void query3(int n, int l, int r, int d, int x) {
	propagate(n, d);
	if (l > r) return;
	if (!l && r == d - 1) {
		lazy[n] = x;
		propagate(n, d);
		return;
	}
	// Opcion 3
	d /= 2;
	query3(n << 1, l, min(d - 1, r), d, x);
	query3(2 * n + 1, max(0, l - d), r - d, d, x);
	segmentTree[n] = segmentTree[n << 1] + segmentTree[n << 1 | 1];
}

void query32(int n, int l, int r, int d, int x) {
	propagate2(n, d);
	if (l > r) return;
	if (!l && r == d - 1) {
		lazy2[n] = x;
		propagate2(n, d);
		return;
	}
	// Opcion 3
	d /= 2;
	query32(n << 1, l, min(d - 1, r), d, x);
	query32(2 * n + 1, max(0, l - d), r - d, d, x);
	segmentTree2[n] = segmentTree2[n << 1] + segmentTree2[n << 1 | 1];
}

int main() {
    int n;
    int Q, l, r, t, x, acum;
    cin >> n;
    FOR(i, 0, n) {
        cin >> a[i];
    }
    ss = 1 << (int)ceil(log2(n));
    precalcSegmentTree(n);
    FOR(i, 0, n) {
        l = i;
        r = n - 1;
        b[i] = query(1, l, r, ss);
    }
    precalcSegmentTree2(n);

    cin >> Q; // Cantidad de queries
    FOR(i, 0, Q) {
        acum = 0;
        cin >> t >> l >> r;
        l--; r--;
        if (t == 1) {
            acum = queryB(1, l, r, ss);    
            cout << acum << endl;
        }
        else if (t == 2) {
            query32(1, l, l, ss, r);
        }
    }
    return 0;
}