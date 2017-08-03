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

int cant;
double nums[200000];

double max(double a, double b) {
	if(a < b) {
		return b;
	}
	return a;
}

double min(double a, double b) {
	if(a < b) {
		return a;
	}
	return b;
}

double calc(double m) {
	double sum, a, b;
	sum = a = b = 0;

	FOR(x, 0, cant) {
		sum += nums[x] - m;
		a = max(sum, a);
		b = min(sum, b);
	}

	return abs(a - b);
}

int main()
{
	cin >> cant;

	FOR(x, 0, cant) {
		cin >> nums[x];
	}

	double low = -200000, hi = 200000;
	double m1, m2, fxm1, fxm2;

	FOR(i, 0, 115) {
		m1 = (low + low + hi) / 3;
		m2 = (low + hi + hi) / 3;

		fxm1 = calc(m1);
		fxm2 = calc(m2);

		if(fxm1 < fxm2) {
			hi = m2;
		}

		if(fxm2 < fxm1) {
			low = m1;
		}
	}

	printf("%.9f\n", fxm1);
	return 0;

}