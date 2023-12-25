#include<iostream>
#include<vector>
#include<stack>
#include<set>
#include<unordered_set>
#include<map>
#include<unordered_map>
#include<numeric>
#include<math.h>
#include<algorithm>
#include<queue>
#include<string>
#include<random>
#include<time.h>
#include<cstring>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define endl '\n'
int main() {
	ios::sync_with_stdio(0);
	cout.tie(0);
	ll n,m;
	cin>>n>>m;
	ll MOD=1e9+7;
	if(n==1) {
		cout<<m+1;
	} else {
		vector<vector<vector<ll>>> dp(n,vector<vector<ll>>(m+1,vector<ll>(m+1)));
		auto dps=dp;
		for(int i=0; i<=m; i++) {
			for(int j=0; j<=m; j++) {
				if(i+j<=m) dp[1][i][j]=1;
			}
		}
		for(int i=2; i<n; i++) {
			dps[i-1]=dp[i-1];
			for(int j=0; j<=m; j++) {
				for(int k=1; k<=m; k++) {
					dps[i-1][k][j]+=dps[i-1][k-1][j];
					dps[i-1][k][j]%=MOD;
				}
			}
		}
		for(int j=0; j<=m; j++) {
			for(int k=0; k<=m; k++) {
				if(j+k>m) dp[i][j][k]=0;
				else dp[i][j][k]=dps[i-1][m-j-k][j];
			}
		}
		ll ans=0;
	}
	for(int i=0; i<=m; i++) {
		for(int j=0; j<=m; j++) {
			ans+=dp[n-1][i][j];
			ans%=MOD;
		}
	}
	cout<<ans;
}
return 0;
}
