#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

vector<pair<ll, ll> > ch[100005]; //用于记录孩子节点和边权 
ll depth[100005] = {0}; //用于记录每个结点的深度 
ll pa[100005] = {0}; //记录每个节点的父亲 
ll dp[100005][18] = {0}; //记录每个结点的前2^j个祖宗是谁 
ll d[100005] = {0}; //记录从根节点到某个节点的距离 
ll n, k; 
ll kk[100005] = {0}; 
ll sum = 0;

void init(ll curr, ll de, ll val);
ll lca(ll a, ll b);
ll getPath(ll a, ll b);

int main(){
	cin >> n >> k;
	for(int i = 1; i <= n - 1; i++){
		ll a, b, c;
		cin >> a >> b >> c;
		ll nowpa = min(a, b), nowch = max(a, b);
		pa[nowch] = nowpa;
		ch[nowpa].push_back(make_pair(nowch, c));
	}
	for(int i = 1; i <= k; i++){
		cin >> kk[i];
	}
	//初始化深度 
	init(1, 1, 0);
	//初始化dp数组：
	//dp[i][j] = dp[dp[i][j - 1]][j - 1] 
	for(int i = 1; i <= n; i++){
		dp[i][0] = pa[i];
		for(int j = 1; j <= 17; j++){
			dp[i][j] = dp[dp[i][j - 1]][j - 1];
		}
	}
	for(int i = 1; i <= k; i++){
		sum += getPath(kk[i - 1], kk[i]);
	}
	for(int i = 1; i <= k; i++){
		ll ans = sum - getPath(kk[i - 1], kk[i]) - getPath(kk[i], kk[i + 1]) + getPath(kk[i - 1], kk[i + 1]);
		cout << ans << " ";
	}
	cout << "\n";
	return 0;
}

void init(ll curr, ll de, ll val){
	depth[curr] = de;
	d[curr] = val;
	for(auto it = ch[curr].begin(); it != ch[curr].end(); it++){
		init(it->first, de + 1, val + it->second);
	}
}

//lca函数 
ll lca(ll a, ll b){
	//使a的深度尽可能小 
	if(depth[a] > depth[b]){
		ll temp = b;
		b = a;
		a = temp;
	}
	//使a，b都在同一深度 
	for(int i = 17; i >= 0; i--){
		if(depth[a] <= depth[dp[b][i]]){
			b = dp[b][i];
		} 
		if(a == b) return a;
	}
	//使用倍增 
	for(int i = 17; i >= 0; i--){
		if(dp[a][i] != dp[b][i]){
			a = dp[a][i];
			b = dp[b][i];
		}
	}
	return dp[a][0];
}

ll getPath(ll a, ll b){
	if(a == 0 || b == 0) return 0;
	ll l = lca(a, b);
	return d[a] + d[b] - d[l] * 2;
}
