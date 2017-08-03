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

int pairs[100000][2];

int main(int argc, char const *argv[])
{
	int n, l = 0, r = 0, res = 0, beauty, tmp, help = 0, max = 0, total_l, total_r;
	cin >> n;
	FOR(i, 0, n) {
		cin >> pairs[i][0] >> pairs[i][1];
		l += pairs[i][0];
		r += pairs[i][1];
	}
	total_l = l;
	total_r = r;
	beauty = abs(l - r);
	FOR(i, 0, n) {
		tmp = abs(pairs[i][0] - pairs[i][1]);
		if(pairs[i][0] > pairs[i][1]) {
			l -= tmp;
			r += tmp;
			help = abs(l - r);
		}	
		if(pairs[i][0] < pairs[i][1]) {
			l += tmp;
			r -= tmp;
			help = abs(l - r);
		}
		if(help > max && help > beauty) {
			res = i + 1;
			max = help;
		}
		l = total_l;
		r = total_r;
	}
	cout << res << endl;
	return 0;
}