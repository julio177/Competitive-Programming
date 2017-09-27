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

bool check(string a, string b) {
    if (a == b) {
        return true;
    }
    int tam = a.size() % 2;
    if (tam != 0) {
        return false;
    }
    string a1, a2, b1, b2;
    tam = a.size() >> 1;
    a1 = a.substr(0, tam);
    a2 = a.substr(tam);
    b1 = b.substr(0, tam);
    b2 = b.substr(tam);

    if (check(a1, b2) && check(a2, b1)) {
        return true;
    }
    else if (check(a1, b1) && check(a2, b2)) {
        return true;
    }
    return false;
}

int main() {
    // set up
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    // read
    string a, b;
    cin >> a >> b;
    // recursive check
    if (check(a, b)) {
        cout << "YES" << endl;
    }
    else {
        cout << "NO" << endl;
    }
    return 0;
}