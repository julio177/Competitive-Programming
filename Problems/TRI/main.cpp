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
	int a, b, c, i = 1;
	string res;
	vs results;
	while(cin >> a >> b >> c) {
		res = "";
		if(a + b == c) {
			res = to_string(a) + "+" + to_string(b) + "=" + to_string(c);
		}
		else if(a == b + c) {
			res = to_string(a) + "=" + to_string(b) + "+" + to_string(c);
		}
		else if(a - b == c) {
			res = to_string(a) + "-" + to_string(b) + "=" + to_string(c);
		}
		else if(a == b - c) {
			res = to_string(a) + "=" + to_string(b) + "-" + to_string(c);
		}
		else if(a * b == c) {
			res = to_string(a) + "*" + to_string(b) + "=" + to_string(c);
		}
		else if(a == b * c) {
			res = to_string(a) + "=" + to_string(b) + "*" + to_string(c);
		}
		else if( a / b == c) {
			res = to_string(a) + "/" + to_string(b) + "=" + to_string(c);
		}
		else if( a == b / c) {
			res = to_string(a) + "=" + to_string(b) + "/" + to_string(c);
		}
		res = "Case " + to_string(i) + ": " + res;
		results.pb(res);
		i += 1;
	}
	return 0;
}