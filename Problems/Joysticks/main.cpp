#include <bits/stdc++.h>
#define INF 1000000000
#define FOR(i, a, b) for(int i=int(a); i<int(b); i++)
#define FORC(cont, it) for(decltype((cont).begin()) it = (cont).begin(); it != (cont).end(); it++)
#define pb push_back
#define maxN 1004
#define MOD 1000000007

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;

int main(int argc, char const *argv[])
{
	int a, b, cont;
	cont = 0;
	cin >> a >> b;

	if(a == 1 && b == 1) {
		cout << 0 << endl;
	}
	else {
		while(a && b) {
			if(a <= b) {
				a++;
				b -= 2;
			}
			else {
				b++;
				a -=2;
			}
			cont++;
		}
		cout << cont << endl;
	}
	return 0;
}