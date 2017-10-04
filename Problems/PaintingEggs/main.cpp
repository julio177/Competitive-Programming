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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, a, g, aux;
    ll suma, sumb, dif;
    string res;
    cin >> n;
    dif = 0;
    suma = 0;
    sumb = 0;
    FOR(i, 0, n) {
        cin >> a >> g;
        if (a + suma - sumb < 500) {
            suma += a;
            res += "A";
        }
        else {
            sumb += g;
            res += "G";
        }
    }
    cout << res << endl;
    return 0;
}