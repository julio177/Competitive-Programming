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
#include <string>

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
	int n, min = 1000, max = 0;
	vii results;
	vi scores(10, 0);
	bool erase_min, erase_max;
	erase_min = erase_max = false;

	cin >> n;

	FOR(i, 0, n) {
		results.pb(make_pair(i + 1, 0));
		FOR(j, 0, 10) {
			cin >> scores[j];
			if(scores[j] < min) min = scores[j];
			if(scores[j] > max) max = scores[j];
		}

		FOR(j, 0, 10) {
			if(!erase_min && scores[j] == min) {
				erase_min = true;
				scores[j] = 0;
			}
			else if(!erase_max && scores[j] == max) {
				erase_max = true;
				scores[j] = 0;
			}
			else {
				results[i].second += scores[j];
				scores[j] = 0;
			}
		}
		erase_min = false;
		erase_max = false;
		min = 1000;
		max = 0;
	}
	FOR(i, 0, n) {
		cout << results[i].first << " " << results[i].second << endl;
	}
	return 0;
}