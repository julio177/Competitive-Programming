#include <bits/stdc++.h>
#define ll long long int
using namespace std;
const int maxN=1e6+100,mod=1e9+7,CH=26;
ll n,m,a[maxN],res,ans=1;
int main(){
	string s;
	cin>>n>>m>>s;
	res=n;
	for(ll i=0;i<m;i++){
		cin>>a[i];
		if (!i||a[i]-a[i-1]>=s.size())//thank god :)))
            res-=s.size();
		else{
            if (s[a[i]-a[i-1]]!=s[0]) {
            cout<<0<<endl;
            return 0;
            }
            else res-=(a[i]-a[i-1]);
        }
	}
	for(ll i=0;i<res;i++)
        ans=(ans*CH)%mod;
	cout<<ans<<endl;
}