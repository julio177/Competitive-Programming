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
typedef vector<ii> vii;
typedef vector<vi> vvi;

struct Element {
    ll val;
    int index;
    int used;
    bool operator<(const Element& rhs) const {
        if (val == rhs.val) {
            return index > rhs.index;
        }
        return val < rhs.val;
    }
};



int main() {
    priority_queue<Element> e;
    vi numbers(100000, 0);
    ll n, k, helper, sum, current, dif;
    sum = 0;
    Element aux;
    cin >> n >> k;

    FOR(i, 0, n) {
        cin >> helper;
        numbers.pb(helper);
        sum += helper;
        aux = {helper, i, 0};
        e.push(aux);
    }

    // while (!e.empty()) {
    //     cout << e.top().val << " ";
    //     e.pop();
    // }
    if (sum == 0) {
        cout << sum << endl;
        FOR(i, 0, n) {
            cout << numbers[i] << " ";
        }
        return 0;
    }
    
    while(k > 0 && sum > 0) {
        aux = e.top();
        e.pop();
        if (e.empty() || e.top().val == 0) {
            dif = ceil(log2(aux.val));
        }
        else {
            dif = ceil(log2(aux.val) - log2(e.top().val));
        }
        helper = aux.val;
        if (dif == 0) {
            dif = 1;
        }
        else if (dif > k) {
            dif = k;
        }
        aux.val >>= dif;
        aux.used += dif;
        e.push(aux);
        sum -= (helper - aux.val);
        k -= dif;
    }

    cout << sum << endl;
    while (!e.empty()) {
        aux = e.top();
        e.pop();
        numbers[aux.index] = aux.used;
    }
    FOR(i, 0, n) {
        cout << numbers[i] << " ";
    }
    return 0;
}