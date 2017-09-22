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

int n, d, maxi, start, nxt[100005], answer[100005];
ll h[100005];

int main() {
    cin >> n >> d;
    FOR(i, 1, n + 1) {
        cin >> h[i];
        nxt[i] = -1;
        answer[i] = 1;
    }

    // Start from the back
    for(int i = n; i >= 1; i--) {
        // 
        for(int j = i + 1; j <= min(i + 250, n); j++) {
            if(abs(h[i] - h[j]) >= d && answer[i] < answer[j] + 1) {
                nxt[i] = j;
                answer[i] = answer[j] + 1;
                if(answer[i] > maxi) {
                    maxi = answer[i];
                    start = i;
                } 
            }
        }
    }
    cout << maxi << endl;

    while(start != -1) { 
        cout << start << " "; 
        start = nxt[start]; 
    }
}