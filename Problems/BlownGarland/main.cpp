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

string checkSequence(string s) {
	string res = "XXXX";

	for(int i = 0; i < s.size(); i += 4) {
		if(s[i] != '!') {
			res[i % 4] = s[i];
		}

		if((i + 1) < s.size() && s[i + 1] != '!') {
			res[(i + 1) % 4] = s[i + 1];
		}

		if((i + 2) < s.size() && s[i + 2] != '!') {
			res[(i + 2) % 4] = s[i + 2];
		}

		if((i + 3) < s.size() && s[i + 3] != '!') {
			res[(i + 3) % 4] = s[i + 3];
		}
	}
	return res;
}

int main()
{
	string s, sequence;
	int r, g, b, y;
	r = g = b = y = 0;
	cin >> s;
	sequence = checkSequence(s);

	FOR(i, 0, s.size()) {
		if(s[i] == '!') {
			if(sequence[i % 4] == 'R') r++;
			if(sequence[i % 4] == 'G') g++;
			if(sequence[i % 4] == 'B') b++;
			if(sequence[i % 4] == 'Y') y++;
		}
	}

	cout << r << " " << b << " " << y << " " << g << endl;

	return 0;
}