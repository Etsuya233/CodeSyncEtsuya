#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;

typedef struct GraphNode{
	int magic, i, j, t;
} noda;
int n, k;
int arr[1005][1005] = {0};
int vis[1005][1005];
int ii[4] = {0, 1, 0, -1};
int jj[4] = {1, 0, -1, 0};
noda tempa;
int ans = 0x7fffffff;

void bfs();

int main(){
	cin >> n >> k;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			char now;
			cin >> now;
			if(now == '#'){
				arr[i][j] = 1;
			} else if(now == 'X'){
				arr[i][j] = 2;
			} else if(now == '%'){
				arr[i][j] = 3;
			}
		}
	}
	memset(vis, -1, sizeof(vis));
	bfs();
	if(ans == 0x7fffffff) cout << -1;
	else cout << ans;
}

void bfs(){
	queue<noda> my;
	tempa.i = 1;
	tempa.j = 1;
	tempa.magic = (arr[1][1] == 3)? k: 0;
	tempa.t = 0;
	my.push(tempa);
	vis[1][1] = tempa.magic;
	while(!my.empty()){
		int nowi = my.front().i, nowj = my.front().j, nowMagic = my.front().magic, nowt = my.front().t;
		my.pop();
		vis[nowi][nowj] = nowMagic;
		if(nowi == n && nowj == n){
			ans = min(ans, nowt);
			break;
		}
		for(int i = 0; i < 4; i++){
			int nexti = nowi + ii[i], nextj = nowj + jj[i];
			if(nexti >= 1 && nexti <= n && nextj >= 1 && nextj <= n && vis[nexti][nextj] < nowMagic && arr[nexti][nextj] != 1){
				if(arr[nexti][nextj] == 2 && nowMagic <= 0) continue;
				tempa.i = nexti;
				tempa.j = nextj;
				tempa.magic = (nowMagic > 0)? nowMagic - 1: 0;
				if(arr[nexti][nextj] == 3) tempa.magic = k;
				tempa.t = nowt + 1;
				my.push(tempa);
			}
		}
	}
}
