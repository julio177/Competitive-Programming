#include <bits/stdc++.h>

#define INF 1000000000
#define FOR(i, a, b) for(int i=int(a); i<int(b); i++)
#define RFOR(i, a, b) for(int i=int(a)-1; i>=int(b); i--)
#define FORC(cont, it) for(typeof((cont).begin()) it = (cont).begin(); it != (cont).end(); it++)
#define RFORC(cont, it) for(typeof((cont).rbegin()) it = (cont).rbegin(); it != (cont).rend(); it++)
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<string> vs;
typedef stack<int> si;
typedef stack<string> ss;
typedef vector<ii> vii;
typedef vector<vi> vvi;

vi used(1000007, 0);
vi numbers(1000007, 0);
vi distinct(1000007, 0);

void calc(int n) {
    RFOR(i, n, 0) {
        if (used[numbers[i]]) {
            distinct[i] = distinct[i + 1]; 
        }
        else {
            distinct[i] = distinct[i + 1] + 1;
            used[numbers[i]] = 1;
        }
    }
}

int main() {
    int n, m, val;
    cin >> n >> m;
    FOR(i, 0, n) {
        cin >> numbers[i];
    }
    calc(n);
    FOR(i, 0, m) {
        cin >> val;
        cout << distinct[val - 1] << endl;
    }
    return 0;
}