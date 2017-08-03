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
	int a = 0, e = 0, i = 0, o = 0, u = 0;
	string s;
	while(getline(cin, s)) {
		FOR(j, 0, s.size()) {
			if(s[j] == 'a' || s[j] == 'A')
				a++;
			else if(s[j] == 'e' || s[j] == 'E')
				e++;
			else if(s[j] == 'i' || s[j] == 'I')
				i++;
			else if(s[j] == 'o' || s[j] == 'O')
				o++;
			else if(s[j] == 'u' || s[j] == 'U')
				u++;
		}
	}
	cout << a << ' ' << e << ' ' << i << ' ' << o << ' ' << u << endl;
	return 0;
}