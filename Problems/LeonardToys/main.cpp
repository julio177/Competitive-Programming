#include <bits/stdc++.h>
#define INF 1000000000
#define FOR(i, a, b) for(int i=int(a); i<int(b); i++)
#define FORC(cont, it) for(decltype((cont).begin()) it = (cont).begin(); it != (cont).end(); it++)
#define pb push_back
#define maxN 200000

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;

ll dp[maxN], toys[maxN];
ll N;

int main(int argc, char const *argv[])
{
	int tests;
	cin >> tests;
	FOR(i, 0, tests) {
		scanf("%d", &N);
		
		memset(dp, 0, sizeof(dp));
		memset(toys, 0, sizeof(toys));

		FOR(j, 0, N) {
			scanf("%d", &toys[j]);
		}

		for(int j = N - 1; j >= 0; j--) {
			dp[j] = max(toys[j] + dp[j + 2], max(toys[j] + toys[j + 1] + dp[j + 4], toys[j] + toys[j + 1] + toys[j + 2] + dp[j + 6]));
		}
		
		printf("%lld\n", dp[0]);
	}
	return 0;
}