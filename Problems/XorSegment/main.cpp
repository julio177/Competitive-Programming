#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <queue>
#include <map>
#include <numeric>
#include <set>
#include <sstream>
#include <stack>
#include <utility>
#include <vector>

#define INF 1000000000
#define FOR(i, a, b) for(int i=int(a); i<int(b); i++)
#define FORC(cont, it) for(decltype((cont).begin()) it = (cont).begin(); it != (cont).end(); it++)
#define pb push_back
#define maxN 100000

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;

int main(int argc, char const *argv[])
{
	ll a[maxN];
	int N, Q, t, l, r, x, count, tmp;
	long long int sum;
	scanf("%d", &N);
	FOR(i, 0, N) {
		scanf("%d", &a[i]);
	}
	scanf("%d", &Q);
	FOR(i, 0, Q) {
		scanf("%d", &t);
		if(t == 1) {
			sum = 0;
			scanf("%d %d", &l, &r);
			tmp = 0;
			count = 0;
			FOR(j, l - 1, r) {
				count++;
				if(count == 2000) {
					sum += tmp;
					tmp = 0;
					count = 0;
				}
				tmp += a[j];
			}
			sum += tmp;
			printf("%I64d\n", sum);
		}
		else {
			scanf("%d %d %d", &l, &r, &x);
			FOR(j, l - 1, r) {
				a[j] ^= x;
			}
		}
	}
	return 0;
}