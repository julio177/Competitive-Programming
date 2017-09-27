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

bool isSub(string a, string b) {
    int x = 0;
    FOR(i, 0, b.size()) {
        if (a[x] == b[i]) {
            x++;
        }
        else if (a[x] == ' ') {
            x++;
        }
        if (x == a.size()) {
            return true;
        }
    }
    return false;
}

int main() {
    // set up
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int permutations[200000];

    string t, p, nueva;
    cin >> t;
    cin >> p;

    FOR(i, 0, t.size()) {
        cin >> permutations[i];
    }

    int l, r, m;
    l = 0;
    r = t.size();

    while (l <= r) {
        m = (l + r) >> 1;
        nueva = t;
        FOR(i, 0, m) {
            nueva[permutations[i] - 1] = ' ';
        }
        if (isSub(p, nueva)) {
            l = m + 1;
        }
        else {
            r = m - 1;
        }
    }
    cout << l - 1 << endl;
    return 0;
}