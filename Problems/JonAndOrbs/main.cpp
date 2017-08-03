#include <bits/stdc++.h>
#define INF 1000000000
#define FOR(i, a, b) for(int i=int(a); i<int(b); i++)
#define FORC(cont, it) for(decltype((cont).begin()) it = (cont).begin(); it != (cont).end(); it++)
#define pb push_back
#define maxN 1004

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;

const double eps = 1e-7;
double dp[maxN];
int ans[maxN];

int main(int argc, char const *argv[])
{
	int k, q, p;
	cin >> k >> q;
	int count = 1;
	dp[0] = 1;

	for(int n = 1; count <= 1000; n++) {
		for(int x = k; x > 0; --x) {
			dp[x] = (x * dp[x] + (k - x + 1) * dp[x - 1]) / k;
			cout << dp[x] << endl;
		}
		count++;
	}

	return 0;
}