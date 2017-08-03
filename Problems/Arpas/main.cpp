#include <iostream>
#include <math.h> 

using namespace std;

typedef long long ll;


// a*b%m;
// O(logN)
ll mulmod(ll a, ll b, ll m) {
	ll ret = 0;
	while (b) {
		if (b & 1) ret = (ret + a) % m; // Problema interesante: supongamos que ret+a puede excederse de 2^64 bits, como hacerle para no tener overflow??
		a = (a << 1) % m; 
		b >>= 1;
	}
	return ret;
}

// x^n mod m (tambien se usa la notacion x**n mod m)
// O(logN)
ll fastPow(ll x, ll n, ll m) {
	ll ret = 1;
	while (n) {
		if (n & 1) ret = mulmod(ret,x, m); // Recordar que solo lo tenemos que usar si MOD>2^32, sino usar ret=ret*x%m;, ya que es tiempo constante
		x = mulmod(x,x, m);
		n >>= 1;
	}
	return ret;
}

int main()
{
	ll n;
	cin >> n;
	cout << fastPow(8, n, 10) << endl;
	return 0;
}
