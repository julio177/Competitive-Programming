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
#define FOR(i, a, b) for(int i = int(a); i < int(b); i++)
#define FORC(cont, it) for(decltype((cont).begin()) it = (cont).begin(); it != (cont).end(); it++)
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;

ll n, m, k, x, y, c;
ll mat[100][100];

int main()
{
	cin >> n >> m >> k >> x >> y;
	ll full_periods, remaining, individual, T;

	if(n == 1) {
		T = m;
		full_periods = k / T;
		remaining = k % T;
		// Max
		remaining > 0 ? cout << (full_periods + 1) : cout << full_periods;
		cout << " ";
		// Min
		cout << full_periods << " ";
		// Individual
		if((x * y) <= remaining) {
			cout << (full_periods + 1) << endl;
		} 
		else {
			cout << full_periods << endl;
		}
	}
	else if(k < (m * n)) {
		cout << 1 << " " << 0 << " ";
		(((x - 1) * m) + y) <= k ? cout << 1 << endl : cout << 0 << endl;
 	}
	else if(k == m * n) {
		cout << 1 << " " << 1 << " " << 1 << endl;
	}
	else {
		int s = m * (n + (n - 2));
		full_periods = k / s;
		remaining = k % s;
		FOR(i, 0, n) {
			FOR(j, 0, m) {
				if(i == 0 || i == n - 1) {
					mat[i][j] = full_periods;
				} else {
					mat[i][j] = full_periods * 2;
				}
				//cout << mat[i][j] << " ";
			}
			//cout << endl;
		}
		// cout << remaining << endl;
		bool flag = false;
		int i, j;
		i = j = 0;

		while(remaining > 0) {
			mat[i][j]++;
			remaining--;

			j++;
			if(j == m) {
				j = 0;
				if(flag) {
					i--;
				} else {
					i++;
				}
				if(i == n) {
					flag = true;
					i -= 2;
				}
			}
		}

		ll min = 10000000000000000, max = 0;
		FOR(i, 0, n) {
			FOR(j, 0, m) {
				if(mat[i][j] < min) min = mat[i][j];
				if(mat[i][j] > max) max = mat[i][j];
				//cout << mat[i][j] << " ";
			}
			//cout << endl;
		}
		cout << max << " " << min << " " << mat[x - 1][y - 1] << endl;
	}

	return 0;
}