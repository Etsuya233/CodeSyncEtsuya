#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

int n, m;
vector<int> g[10002];
int vis[10005] = {0};
queue<int> ne;
int ans[10005] = {0};

int main(){
	cin >> n >> m;
	for(int i = 0; i < m; i++){
		int a, b, c;
		cin >> a >> b >> c;
		if(a == 1){
			if(b == c) continue;
			g[b].push_back(c);
			g[c].push_back(b);
		} else {
			memset(vis, 0, sizeof(vis));
			ne.push(b);
			vis[b] = 1;
			while(!ne.empty()){
				int now = ne.front();
				ne.pop();
				ans[now] += c;
				for(int j = 0; j < g[now].size(); j++){
					if(vis[g[now][j]] == 0){
						ne.push(g[now][j]);
						vis[g[now][j]] = 1;
					}	
				}
			}
		}
	}
	for(int i = 1; i <= n; i++){
		cout << ans[i] << " ";
	}
	return 0;
}


