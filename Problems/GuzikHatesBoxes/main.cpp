#include <iostream>
#include <vector>
#include <cmath>
#include <cstdio>
 
#define INF 1000000000
#define MIN -100000000
#define FOR(x, y, z) for(int x = int(y);  x < int(z); x++) 
#define FORC(cont, it) for(decltype((cont).begin()) it = (cont).begin(); it != (cont).end(); it++)
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;

ll t, n, m, s, a[100010], sum, l, r, mid;
int i, st;

int validate(ll x) {
	int t = m;
	ll s = 0;
	FOR(i, 1, st + 1) {
		// suma valores de las cajas
		s += a[i];
		// suma y espacios mayor al tiempo
		while(s + i > x) {
			// a la cantidad le restamos tiempo y espacios
			s -= x - i;
			// restamos persona
			t--;
			if(t < 0) {
				return 0;
			}
		}
	}
	if(t == 0) {
		return s <= 0;
	}
	return 1;
}

int main() {
	cin >> n >> m;
	FOR(i, 1, n + 1) {
		scanf("%d", &a[i]);
		// sum qty of boxes
		sum += a[i];
		// store last pos with boxes
		if(a[i]) {
			st = i;
		}
	}
	// st = time to last pile of boxes with boxes
	// min time with 1 box 1 person
	l = st + 1;
	// max time with all boxes 1 person
	r = sum + st;
	while(l <= r) {
		// divide by 2
		mid = (l + r) >> 1;
		// checar funcion de validacion con tiempo medio
		if(validate(mid)) {
			r = mid - 1;
		}
		else {
			l = mid + 1;
		}
	}
	cout << r + 1 << endl;
}