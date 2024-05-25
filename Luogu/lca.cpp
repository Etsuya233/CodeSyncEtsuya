#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

vector<pair<int, int> > ch[100005];
int depth[100005] = {0};
int pa[100005] = {0};
int dp[100005][18] = {0};
int d[100005] = {0};
int n, k;
int kk[100005] = {0};
int sum = 0;

void init(int curr, int de, int val);
int lca(int a, int b);
int getPath(int a, int b);

int main(){
	cin >> n >> k;
	for(int i = 1; i <= n - 1; i++){
		int a, b, c;
		cin >> a >> b >> c;
		int nowpa = min(a, b), nowch = max(a, b);
		pa[nowch] = nowpa;
		ch[nowpa].push_back(make_pair(nowch, c));
	}
	for(int i = 1; i <= k; i++){
		cin >> kk[i];
	}
	//depth
	init(1, 1, 0);
	//dp arr[i][j] = arr[arr[i][j - 1]][j - 1] 
	for(int i = 1; i <= n; i++){
		dp[i][0] = pa[i];
		for(int j = 1; j <= 17; j++){
			dp[i][j] = dp[dp[i][j - 1]][j - 1];
		}
	}
	//calc
	for(int i = 1; i <= k; i++){
		sum += getPath(kk[i - 1], kk[i]);
	}
	for(int i = 1; i <= k; i++){
		int ans = sum - getPath(kk[i - 1], kk[i]) - getPath(kk[i], kk[i + 1]) + getPath(kk[i - 1], kk[i + 1]);
		cout << ans << " ";
	}
	cout << "\n";
	return 0;
}

void init(int curr, int de, int val){
	depth[curr] = de;
	d[curr] = val;
	for(auto it = ch[curr].begin(); it != ch[curr].end(); it++){
		init(it->first, de + 1, val + it->second);
	}
}

int lca(int a, int b){
	if(depth[a] > depth[b]){
		int temp = b;
		b = a;
		a = temp;
	}
	//same depth
	for(int i = 17; i >= 0; i--){
		if(depth[a] <= depth[dp[b][i]]){
			b = dp[b][i];
		} 
		if(a == b) return a;
	}
	//get same ancestor
	for(int i = 17; i >= 0; i--){
		if(dp[a][i] != dp[b][i]){
			a = dp[a][i];
			b = dp[b][i];
		}
	}
	return dp[a][0];
}

int getPath(int a, int b){
	if(a == 0 || b == 0) return 0;
	int l = lca(a, b);
	return d[a] + d[b] - d[l] * 2;
}
