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

#define maxN 200000
#define logMaxN 20

ll N, a[maxN];
ll segmentTree[4 * maxN], ss;

void printeame(){
	FOR(i, 0, ss + N){
		cout << segmentTree[i] << " ";
	}
	cout << endl;
}

void precalcSegmentTree(ll N) {
	// Reseteamos los valores y ponemos cosas ignorables
	memset(segmentTree, 0, sizeof(segmentTree));

	FOR(i, 0, ss) {
		segmentTree[ss + i] = 0;
	}
	// almacenamos las hojas
	FOR(i, 0, N) {
		segmentTree[ss + i] = a[i];
	}

	// Precalcular el resto del arbol
	ll tmp, actual;
	bool op = true;
	tmp = (int)ceil(log2(ss - 1));

	for (ll i = ss - 1; i; i--) {
		// Recordar que i<<1 == 2*i y 1<<1|1 == 2*1+1
		// segmentTree[i] = segmentTree[2 * i] + segmentTree[2 * i + 1];
		actual = (int)ceil(log2(i));

		

		if(op) {
			segmentTree[i] = segmentTree[i << 1] | segmentTree[i << 1 | 1];
		}
		else {
			segmentTree[i] = segmentTree[i << 1] ^ segmentTree[i << 1 | 1];
		}
		if(tmp != actual) {
			tmp = actual;
			op = !op;
		}
		//cout << segmentTree[i] << " ";
	}
	//cout << endl;
}

void modify(int n, ll x) {
	segmentTree[n] = x;
	bool op = true;

	while (n >>= 1) {
		if(op) {
			segmentTree[n] = segmentTree[n << 1] | segmentTree[n << 1 | 1];
		}
		else {
			segmentTree[n] = segmentTree[n << 1] ^ segmentTree[n << 1 | 1];
		}
		op = !op;
	}
}

int main(int argc, char const *argv[])
{
	ll Q, num, val;
	cin >> N >> Q;
	N = pow(2, N);
	FOR(i, 0, N) {
		cin >> a[i];
	}

	ss = 1 << (int)ceil(log2(N));
	precalcSegmentTree(N);

	FOR(i, 0, Q) {
		cin >> num >> val;
		modify(num - 1 + ss, val);
		cout << segmentTree[1] << endl;
	}
	return 0;
}