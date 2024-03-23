#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

typedef struct Line{
	int t, d, l, e;
} li;

li arr[20];
int vis[20] = {0};
int t, n;
bool flag = false;

void dfs(int layer, int now);

int main(){
	cin >> t;
	while(t--){
		cin >> n;
		for(int i = 1; i <= n; i++){
			cin >> arr[i].t >> arr[i].d >> arr[i].l;
			arr[i].e = arr[i].d + arr[i].t + arr[i].l;
		}
		memset(vis, 0, sizeof(vis));
		flag = false;
		dfs(1, 0);
		cout << (flag? "YES\n": "NO\n");
	}
	return 0;
}

void dfs(int layer, int now){
	if(layer == n + 1){
		flag = true;
		return;
	}
	for(int i = 1; i <= n; i++){
		if(vis[i]) continue;
		vis[i] = 1;
		if(arr[i].t + arr[i].d >= now) dfs(layer + 1, max(now, arr[i].t) + arr[i].l);
		if(flag) return;
		vis[i] = 0;
	}
}
