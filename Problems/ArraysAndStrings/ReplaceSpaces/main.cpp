#include <bits/stdc++.h>

#define INF 1000000000
#define FOR(i, a, b) for(int i=int(a); i<int(b); i++)
#define FORC(cont, it) for(decltype((cont).begin()) it = (cont).begin(); it != (cont).end(); it++)
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

string repalceSpaces(string str) {
    string arr[256];
    FOR(i, 0, str.size()) {
        arr[i] = str[i];
    }
    string nw = "";
    FOR(i, 0, str.size()) {
        if(arr[i] == " ") {
            arr[i] = "x20";
        }
        nw += arr[i];
    }
    return nw;
}

int main() {
    int cases;
    string str;
    cin >> cases;
    FOR(i, 0, cases) {
        getline(cin, str);
        cout << repalceSpaces(str) << endl;
    }
}