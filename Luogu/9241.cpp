#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int m, n;
int t[12], d[12], l[12];
int vis[12] = {0};
bool flag = false;

void dfs(int layer, int tt);

int main(){
	cin >> m;
	while(m--){
		memset(vis, 0, sizeof(vis));
		flag = false;
		cin >> n;
		for(int i = 1; i <= n; i++) cin >> t[i] >> d[i] >> l[i];
		dfs(1, 0);
		if(flag){
			cout << "YES\n";
		} else cout << "NO\n";
	}
	return 0;
}

void dfs(int layer, int tt){
	if(layer == n + 1){
		flag = true;
		return;
	}
	for(int i = 1; i <= n; i++){
		if(vis[i]) continue;
		vis[i] = 1;
		if(tt <= t[i] + d[i]){
			dfs(layer + 1, max(tt, t[i]) + l[i]);
		}
		vis[i] = 0;
		if(flag) return;
	}
}
