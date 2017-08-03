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

int main(int argc, char const *argv[])
{
	int n, total, val, rem;
	string s;
	cin >> n;
	FOR(i, 0, n) {
		total = 0;
		cin.ignore();
		cin >> s;
		FOR(j, 0, s.length()) {
			if(j % 2 == 0) {
				val = (s[j] - '0') * 2;
				if(val >= 10) {
					val = (val / 10) + (val % 10);
					s[j] = '0' + val;
				}
				else {
					s[j] = '0' + val;
				}
			}
			total += s[j] - '0';
		}
		rem = total % 10;
		if (rem > 0){
			cout << 10 - rem << endl;
		}
		else {
			cout << rem << endl;
		}
	}

	return 0;
}