#include <bits/stdc++.h>
#define INF 1000000000
#define FOR(i, a, b) for(int i=int(a); i<int(b); i++)
#define FORC(cont, it) for(decltype((cont).begin()) it = (cont).begin(); it != (cont).end(); it++)
#define pb push_back
#define maxN 1004
#define MOD 1000000007
#define PI 3.14159265358979
#define EPS 1e-7

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;

long double formula(double n, double r) {
	long double top = n * r * r;
	long double down1, down2, ratio;
	ratio = PI / n;
	down1 = 1 / tan(ratio / 2);
	down2 = 1 / tan(ratio);

	return top / (down1 + down2);
}

int main(int argc, char const *argv[])
{
	long double n, r, res;
	cin >> n >> r;
	cout << setprecision(15) << formula(n, r) << endl;
	return 0;
}