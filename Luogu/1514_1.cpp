#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

typedef struct Line{
	int l = 0x7fffffff - 1, r = 0;
} li;

int ii[4] = {0, 1, 0, -1};
int jj[4] = {1, 0, -1, 0};
int arr[505][505] = {0};
int n, m;
int vis[505][505] = {0};
li vis2[505][505];

void bfs(int iii, int jjj);
li dfs(int iii, int jjj);

int main(){
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			cin >> arr[i][j];
		}
	}
	for(int i = 1; i <= m; i++){
		dfs(1, i);
	}
	int cnt = 0;
	for(int i = 1; i <= m; i++){
		if(vis2[n][i].r != 0) cnt++;
	}
	if(cnt == m){
		cout << 1 << "\n";
		cnt = 0;
		int l = 1;
		while(l <= m){
			int maxr =0;
			for(int i = 0; i <= m; i++){
				if(vis2[1][i].l <= l) maxr = max(maxr, vis2[1][i].r);
			}
			l = maxr + 1;
			cnt++;
		}
		cout << cnt;
	} else {
		cout << 0 << "\n" << m - cnt;
	}
	return 0;
}

li dfs(int iii, int jjj){
	li ret;
	if(iii == n){
		ret.l = jjj;
		ret.r = jjj;
	}
	if(vis[iii][jjj]) return vis2[iii][jjj];
	vis[iii][jjj] = 1;
	for(int i = 0; i < 4; i++){
		int nexti = iii + ii[i];
		int nextj = jjj + jj[i];
		int nexth = arr[nexti][nextj];
		if(nexti >= 1 && nexti <= n && nextj >= 1 && nextj <= m && nexth < arr[iii][jjj]){
			li now = dfs(nexti, nextj);
			ret.l = min(ret.l, now.l);
			ret.r = max(ret.r, now.r);
		}
	}
//	cout << iii << " " << jjj << " " << ret.l << " " << ret.r << "\n";
	return vis2[iii][jjj] = ret;
}









