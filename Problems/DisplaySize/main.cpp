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

int main(int argc, char const *argv[])
{
	int n, root;
	float x, y;
	vi nums;
	cin >> n;
	x = sqrt(n);
	y = (int)sqrt(n);

	if(x - y == 0) {
		cout << (int)y << " " << (int)y << endl;
		return 0;
	}

	root = (int)sqrt(n);

	FOR(i, 1, root + 1) {
	    if (n % i == 0)
	        nums.pb(i);
	}

	cout << nums[nums.size() - 1] << " " << (n / nums[nums.size() - 1]) << endl;
	return 0;
}