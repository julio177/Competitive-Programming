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
#define maxN 1000000

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;

int prime(int n) {
	for (int i = 2; i * i <= n; i++) {
		if (n % i ==0) {
			return 0;
		}
	}
	return 1;
}

int main() 
{
	int n;
	cin >> n;
	if(prime(n)) {
		cout << 1 << endl;
	}
	else if(n % 2 == 0 || prime(n - 2)) {
		cout << 2 << endl;
	}
	else {
		cout << 3 << endl;
	}
	return 0;
}