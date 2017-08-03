#include <bits/stdc++.h>
#define INF 1000000000
#define FOR(i, a, b) for(int i=int(a); i<int(b); i++)
#define FORC(cont, it) for(decltype((cont).begin()) it = (cont).begin(); it != (cont).end(); it++)
#define pb push_back
#define maxN 100001

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;

int N;
long long a[3][maxN] = {0};
long long dp[3][maxN] = {0};

int main()
{ 
  cin >> N;
  FOR(i, 0, 3) { 
    FOR(j, 0, N) { 
      cin >> a[i][j];
    }
  }

  int i = N - 1;

  dp[2][i] = a[2][i];
  dp[1][i] = a[1][i] + a[2][i];
  dp[0][i] = dp[1][i] + a[0][i];

  for(i = N - 2; i >= 0; --i) { 
    dp[0][i] = a[0][i] + max(max(max(dp[0][i + 1], a[1][i] + dp[1][i + 1]), a[1][i] + a[2][i] + dp[2][i + 1]), a[0][i + 1] + a[1][i + 1] + a[1][i] + a[2][i] + a[2][i + 1] + dp[2][i + 2]);
    dp[1][i] = a[1][i] + max(max(dp[1][i + 1], a[0][i] + dp[0][i + 1]), a[2][i] + dp[2][i + 1]);
    dp[2][i] = a[2][i] + max(max(max(dp[2][i + 1], a[1][i] + dp[1][i + 1]), a[1][i] + a[0][i] + dp[0][i + 1]), a[2][i + 1] + a[1][i + 1] + a[1][i] + a[0][i] + a[0][i + 1] + dp[0][i + 2]);
  }

  cout << dp[0][0] << endl;
}