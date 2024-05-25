#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

ll n;
ll arr[100005];
vector<ll> tr[100005];
ll pa[100005] = {0};
ll dp[100005] = {0};
ll ans = 0;

void dfs(ll node);

int main(){
	cin >> n;
	for(ll i = 1; i <= n; i++){
		cin >> arr[i];
	}
	for(ll i = 1; i <= n - 1; i++){
		ll a, b;
		cin >> a >> b;
		if(a > b) swap(a, b);
		pa[b] = a;
		tr[a].push_back(b);
	}
	dfs(1);
	cout << ans << "\n";
	return 0;
}

void dfs(ll node){
	dp[node] = arr[node];
//	for(ll c: tr[node]){
//		dfs(c);
//		if(dp[c] > 0) dp[node] += dp[c];
//	}
	for(vector<ll>::iterator it = tr[node].begin(); it != tr[node].end(); it++){
		dfs(*it);
		if(dp[*it] > 0) dp[node] += dp[*it];
	}
	ans = max(ans, dp[node]);
}
