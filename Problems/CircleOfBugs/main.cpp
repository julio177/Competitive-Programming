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

const double PI = 3.141592653589793;

int main(int argc, char const *argv[])
{
	int n, num;
	vi vals(100, 0);
	cin >> n;
	FOR(i, 0, n) {
		cin >> num;
		vals[num - 1]++;
	}
	int goal = 0, pos = 99;
	double acum = 0;
	while(goal < 10) {
		if(vals[pos] ==  0) {
			pos--;
		} else {
			acum += pos + 1;
			vals[pos]--;
			goal++;
		}
	}
	acum = acum / (2.0 * PI);
	printf("%.4f\n", acum);

	return 0;
}