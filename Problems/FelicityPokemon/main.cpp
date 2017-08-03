#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
const int N = 77, INF = 1e9, MOD = 1e9+7;
int n, All;
char a[N];
int d[N][1 << 20], ans;

void mod(int &x) {
	if(x >= MOD) {
		x -= MOD;
	}
}

void dp() {
	for(int i = 0; i <= n; i++) {

		d[i][0] = 1;

		for(int s = 0; s < All; s++) { 
			if(d[i][s] == 0) {
				continue;
			}
			
			if(s && !(s & (s + 1))) {
				mod(ans += d[i][s]);
			}

			int now = 0;

			for(int j = i + 1; j <= n; j++) {
				now = (now << 1) | (a[j] - '0'); //now * 2 + s[i] - '0'

				if(now > 20) {
					break;
				}

				if(now) {
					mod(d[j][s | (1 << (now - 1))] += d[i][s]);
				}
			}
		}
	}
}
int main(){
	scanf("%d%s", &n, a + 1); 
	All = (1 << 20);
	dp();
	printf("%d", ans);
}