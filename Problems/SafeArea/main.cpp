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

struct coord
{
	int x, y;
};

int main(int argc, char const *argv[])
{
	int n;
	double biggestArea = 0, area;
	string biggestId;
	string id;
	coord a, b, c;
	cin >> n;

	FOR(i, 0, n) {
		cin >> id;
		cin >> a.x >> a.y >> b.x >> b.y >> c.x >> c.y;
		area = abs( (double)(( (a.x * (b.y - c.y)) + (b.x * (c.y - a.y)) + (c.x * (a.y - b.y)) ) / 2.0) );
		if(area > biggestArea) {
			biggestArea = area;
			biggestId = id;
		}
	}
	cout << biggestId;
	printf(" %0.2f km^2\n", biggestArea);
	return 0;
}