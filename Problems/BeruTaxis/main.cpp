#include <bits/stdc++.h>
#define INF 1000000000
#define FOR(i, a, b) for(int i=int(a); i<int(b); i++)
#define FORC(cont, it) for(decltype((cont).begin()) it = (cont).begin(); it != (cont).end(); it++)
#define pb push_back
#define maxN 1000

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;

struct Point {
	double x, y;
	bool operator <(const Point &r) const {
		return x < r.x || x == r.x && y < r.y;
	}
};

int N;

double dist(Point &l, Point &r) {
	return sqrt((l.x - r.x)*(l.x - r.x) + (l.y - r.y)*(l.y - r.y));
}

int main(int argc, char const *argv[])
{
	Point home, taxi;

	double distance, res, vel;
	distance = INF;

	cin >> home.x >> home.y;
	cin >> N;

	FOR(i, 0, N) {
		cin >> taxi.x >> taxi.y >> vel;
		res = dist(home, taxi) / vel;
		if(res < distance) {
			distance = res;
		}
	}
	printf("%.20f\n", distance);
	return 0;
}