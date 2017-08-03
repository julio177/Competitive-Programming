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
typedef vector<string> vs;
typedef stack<int> si;
typedef stack<string> ss;
typedef vector<ii> vii;
typedef vector<vi> vvi;

int main(int argc, char const *argv[])
{
	int tests;
	cin >> tests;
	vvi res_miss;
	vvi res_del;
	int n, p, j, f, aux;
	FOR(i, 0, tests) {
		cin >> n >> p >> j >> f;
		vi episodes(n, 0);
		// -2 filler a borrar, -1 filler no grabado, 0, faltante, 1, grabado

		// Jay episodes
		if(j > 0) {
			FOR(x, 0, j) {
				cin >> aux;
				episodes[aux - 1] = 1;
			}
		}

		// Filler episodes
		FOR(x, 0, f) {
			cin >> aux;
			if(episodes[aux - 1]) {
				episodes[aux -1] = -2;
			}
			else {
				episodes[aux -1] = -1;
			}
		}
		// Pavel episodes
		FOR(x, 0, p) {
			if(episodes[x] != 1) {
				episodes[x] = -1;
			}
			if(episodes[x] == 1) {
				episodes[x] = -2;
			}
		}

		vi missv, delv;
		FOR(x, 0, n) {
			if(episodes[x] == 0) {
				missv.pb(x + 1);
			} 
			if(episodes[x] == -2) {
				delv.pb(x + 1);
			}
		}
		res_miss.pb(missv);
		res_del.pb(delv);
		// cout << missv.size() << " ";
		// FOR(x, 0, missv.size()) {
		// 	cout << missv[x] << " ";
		// }
		// cout << endl;
		// cout << delv.size() << " ";
		// FOR(x, 0, delv.size()) {
		// 	cout << delv[x] << " ";
		// }
	}
	FOR(x, 0, res_miss.size()) {
		cout << res_miss[x].size() << " ";
		FOR(i, 0, res_miss[x].size()) {
			cout << res_miss[x][i];
			if(i != res_del[x].size() - 1) {
				cout << " ";
			}
		}
		cout << endl;
		cout << res_del[x].size() << " ";
		FOR(i, 0, res_del[x].size()) {
			cout << res_del[x][i];
			if(i != res_del[x].size() - 1) {
				cout << " ";
			}
		}
		cout << endl;
	}
	return 0;
}