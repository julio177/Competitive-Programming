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
#define maxN 50001

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<string> vs;
typedef stack<int> si;
typedef stack<string> ss;
typedef vector<ii> vii;
typedef vector<vi> vvi;

vi vals(maxN, 0);

int main(int argc, char const *argv[])
{
	int bells, budget, num, sellers;
	cin >> bells >> budget;
	FOR(i, 0, bells) {
		cin >> num;
		vals[num]++;
	}
	int cont = 0, tmp;
	for(int i = 50000; i >= 0; i--) {
		if(vals[i] != 0) {
			tmp = vals[i];
			vals[i] = cont;
			cont += tmp;
		}
		else {
			vals[i] = cont;
		}
	}
	cin >> sellers;
	FOR(i, 0, sellers) {
		cin >> num;
		if(budget / num > 50000)
			cout << 0 << endl;
		else
			cout << vals[budget / num] << endl;
	}
	return 0;
}