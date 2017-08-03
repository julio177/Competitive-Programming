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

int main()
{
	int n, nums[100], max = 0, sum = 0;
	cin >> n;
	FOR(x, 0, n) {
		cin >> nums[x];
		if(nums[x] >= max) {
			max = nums[x];
		}
	}

	FOR(x, 0, n) {
		sum += max - nums[x];
	}

	cout << sum << endl;

	return 0;
}