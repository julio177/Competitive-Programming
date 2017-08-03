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

int main() {
    int n, m;
    cin >> n >> m;
    vi puzzles(m, 0);
    FOR(i, 0, m) {
        cin >> puzzles[i];
    }
    sort(puzzles.begin(), puzzles.end());
    int low = 0;
    int high = n - 1;
    int diff = INF;
    int curr;
    while(high < m) {
        curr = puzzles[high] - puzzles[low];
        diff = curr < diff ? curr : diff;
        low += 1;
        high += 1;
    }
    cout << diff << endl;
    return 0;
}