#include <bits/stdc++.h>
#include <cstdlib>
#include <string>

#define INF 1000000000
#define FOR(i, a, b) for(int i=int(a); i<int(b); i++)
#define RFOR(i, a, b) for(int i=int(a)-1; i>=int(b); i--)
#define FORC(cont, it) for(typeof((cont).begin()) it = (cont).begin(); it != (cont).end(); it++)
#define RFORC(cont, it) for(typeof((cont).rbegin()) it = (cont).rbegin(); it != (cont).rend(); it++)
#define pb push_back
#define MaxN 200000

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
    int w, h, n, val;
    vi H, W, hdif, wdif, res;
    H.reserve(MaxN);
    W.reserve(MaxN);
    hdif.reserve(MaxN);
    wdif.reserve(MaxN);
    res.reserve(MaxN);
    vs instructions;
    instructions.reserve(MaxN);
    string op;
    scanf("%d %d %d", &w, &h, &n);
    H.pb(0); H.pb(h);
    W.pb(0); W.pb(w);
    FOR(i, 0, n) {
        scanf("%s %d", &op, &val);
        if (op == "H") {
            H.pb(val);
        }
        else {
            W.pb(val);
        }
        instructions.pb(op + " " + to_string(val));
    }
    sort(H.begin(), H.end());
    sort(W.begin(), W.end());
    FOR(i, 0, H.size() - 1) {
        val = H[i + 1] - H[i];
        hdif.pb(val);
    }
    FOR(i, 0, W.size()) {
        val = W[i + 1] - W[i];
        wdif.pb(val);
    }
    int maxh, maxw;
    maxh = *max_element(hdif.begin(), hdif.end());
    maxw = *max_element(wdif.begin(), wdif.end());
    string ins;
    RFOR(i, instructions.size(), 0) {
        res.pb(maxh * maxw);
        ins = instructions[i];
        val = atoi(ins.substr(2).c_str());
        if (ins[0] == 'H') {
            auto it = find(H.begin(), H.end(), val);
            auto index = distance(H.begin(), it);
            H.erase(H.begin() + index);
            hdif[index - 1] += hdif[index];
            if (hdif[index - 1] > maxh) {
                maxh = hdif[index - 1];
            }
            hdif.erase(hdif.begin() + index);
        }
        else {
            auto it = find(W.begin(), W.end(), val);
            auto index = distance(W.begin(), it);
            W.erase(W.begin() + index);
            if (wdif[index - 1] > maxh) {
                maxh = wdif[index - 1];
            }
            wdif.erase(wdif.begin() + index);
        }
    }
    RFOR(i, res.size(), 0) {
        printf("%d\n", res[i]);
    }
    return 0;
}