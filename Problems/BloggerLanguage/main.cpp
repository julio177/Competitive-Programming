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

int main() {
    int n = 0;
    int l, r, match, perf_match, tam;
    string sample, check, complete, complete_low, samp_low;
    bool found;

    while(cin >> n >> sample) {
        cin >> complete;
        // sample and check from complete for comparison of match
        // comp low and samp low for  comparison of missmatch
        complete_low = "";
        samp_low = "";
        FOR(i, 0, sample.size()) {
            samp_low += tolower(sample[i]);
        }
        FOR(i, 0, complete.size()) {
            complete_low += tolower(complete[i]);
        }
        
        tam = sample.size();
        // cout << "ref" << endl;
        // cout << complete_low << endl;
        // cout << samp_low << endl;
        // cout << "-----------" << endl;

        FOR(i, 0, n) {
            match = 0;
            perf_match = 0;
            found = false;

            cin >> l >> r;
            l--; r--;
            // cout << "compare" << endl;
            // cout << complete.substr(l, r - l) << endl;
            // cout << sample << endl;
            // cout << "-----------" << endl;
            if (r - l >= tam) {
                FOR(i, l, r - tam) {
                    if (sample == complete.substr(i, tam)) {
                        perf_match++;
                        found = true;
                    }
                    if (samp_low == complete_low.substr(i, tam)) {
                        match++;
                        found = true;
                    }
                }
            }
            FOR(i, l, r) {
                if (isupper(complete[i])) {
                    complete[i] = tolower(complete[i]);
                }
                else {
                    complete[i] = toupper(complete[i]);
                }
            }
            
            if (!found) cout << -1 << endl;
            else cout << match - perf_match << endl;
        }
    }
    return 0;
}