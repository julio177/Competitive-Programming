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
	int n, start, length;
	ss vals;
	string s, aux, res;

	cin >> n;
	vs passwords(n);
	cin.ignore();
	FOR(i, 0, n) {
		getline(cin, s);
		start = length = 0;

		FOR(j, 0, s.size()) {
			if(s[j] == ' ') {
				vals.push(s.substr(start, length));
				length = 0;
				start = j + 1;
			} else {
				length++;
				if(j == s.size() - 1) {
					vals.push(s.substr(start, length));
				}
			}
		}

		passwords[i] = "";
		while(!vals.empty()) {
			if(vals.size() == 1) {
				aux = vals.top();
				vals.pop();
				res = "";
				res.append(aux, 0, 2);
				res.append(passwords[i]);
				res.append(aux, 2, 2);
				passwords[i] = res;
			} else {
				passwords[i] += vals.top();
				vals.pop();
			}
			if(vals.size() >= 2) {
				passwords[i] += "*";
			}
		}
	}
	FOR(i, 0, n) {
		cout << passwords[i] << endl;
	}
	return 0;
}