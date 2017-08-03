#include <bits/stdc++.h>
#define INF 1000000000
#define FOR(i, a, b) for(int i=int(a); i<int(b); i++)
#define FORC(cont, it) for(decltype((cont).begin()) it = (cont).begin(); it != (cont).end(); it++)
#define pb push_back
#define maxN 3000000

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;

int p[maxN];

int main(int argc, char const * arg[]) {
    int t;
    string a, s, b;
    int pp, ansKMP, aux, k, n;
    cin >> t;
    FOR(j, 0, t) {
        cin >> n;
        cin >> s;
        pp = -1, ansKMP = -1;
        p[0] = -1;
        b = s;
        a = b + "$" + s;
        aux = a.length();
        FOR(i, 0, a.length()) {
            while (pp >= 0 && a[pp] != a[i]) pp = p[pp];
            p[i + 1] = ++pp;
            if (pp >= b.length()) {
                ansKMP = i - b.length() + 1;
                break;
            }
        }
        cout << "Test case #" << j + 1 << endl;
        FOR(i, 0, aux + 1) {
            if(i % (i - p[i]) == 0) {
                k = i / (i - p[i]);
            }
            else {
                k = 1;
            }
            if(k > 1) {
                cout << i << " " << k << endl;
            }
            p[i] = 0;
        }
        cout << endl;
    }
}