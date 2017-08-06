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

/*
Remove duplicate characters in string
*/

string removeDuplicates(string s) {
    if(s.size() <= 1) {
        return s;
    }
    char tmp;
    int tail = 1;
    int len = s.size();
    int j;
    for(int i = 1; i < len; i++) {
        for(j = 0; j < tail; j++) {
            if(s[i] == s[j]) {
                break;
            }
        }
        if(j == tail) {
            s[tail] = s[i];
            tail++;
        }
    }
    if(tail != s.size() - 1) {
        FOR(i, tail, s.size()) {
            s[i] = '\0';
        }
    }
    return s;
}

int main() {
    string s;
    cin >> s;

    s = removeDuplicates(s);
    cout << s << endl;
}