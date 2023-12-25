#include <iostream>
using namespace std;

int n, m;
int arr[360] = {0};
int c[5] = {0};
int cc[150] = {0};
int vis[150] = {0};
int ans = 0;

void dfs(int now, int val);

int main(){
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> arr[i];
	}
	for(int i = 1; i <= m; i++){
		int a;
//		cin >> a;
//		c[a]++;
		cin >> cc[i];
	}
//	dfs(1, arr[1]);

/*
		350 * 40 * 40 * 40 * 40
	dp[i][

*/

	cout << ans;
	return 0;
}

void dfs(int now, int val){
	if(now == n){
		ans = max(val, ans);
		return;
	}
	for(int i = 1; i <= m; i++){
		if(!vis[i]){
			vis[i] = 1;
			dfs(now + cc[i], val + arr[now + cc[i]]);
			vis[i] = 0;
		}
	}
}


