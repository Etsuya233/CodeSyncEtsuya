#include <iostream>
#include <queue>
using namespace std;

typedef struct Position{
	int i = -1, j = -1, t = -1;
} po;

int n, m;
int ii[4] = {0, 1, 0, -1};
int jj[4] = {1, 0, -1, 0};
int vis[302][302] = {0};
int si, sj, di, dj;
po telarr[30][2];
char arr[302][302] = {0};

int bfs();

int main(){
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			cin >> arr[i][j];
			if(arr[i][j] >= 'A' && arr[i][j] <= 'Z'){
				if(telarr[arr[i][j] - 'A'][0].i == -1){
					telarr[arr[i][j] - 'A'][0].i = i;
					telarr[arr[i][j] - 'A'][0].j = j;
				} else {
					telarr[arr[i][j] - 'A'][1].i = i;
					telarr[arr[i][j] - 'A'][1].j = j;
				}
			} else if(arr[i][j] == '@'){
				si = i;
				sj = j;
			} else if(arr[i][j] == '='){
				di = i;
				dj = j;
			}
		}
	}
	cout << bfs();
	return 0;
}

int bfs(){
	queue<po> qu;
	po now;
	po next;
	now.i = si;
	now.j = sj;
	now.t = 0;
	qu.push(now);
	while(!qu.empty()){
		now = qu.front();
		qu.pop();
		cout << now.i << " " << now.j << " " << now.t << "\n";
		if(now.i == di && now.j == dj){
			return now.t;
		}
		for(int i = 0; i < 4; i++){
			next.i = now.i + ii[i];
			next.j = now.j + jj[i];
			next.t = now.t + 1;
			if(next.i >= 1 && next.i <= n && next.j >= 1 && next.j <= m && !vis[next.i][next.j] && arr[next.i][next.j] != '#'){
				//Teleport
				if(arr[next.i][next.j] >= 'A' && arr[next.i][next.j] <= 'Z'){
					po temp;
					temp.t = next.t;
					if(next.i == telarr[arr[next.i][next.j] - 'A'][0].i && next.j == telarr[arr[next.i][next.j] - 'A'][0].j){
						temp.i = telarr[arr[next.i][next.j] - 'A'][1].i;
						temp.j = telarr[arr[next.i][next.j] - 'A'][1].j;
					} else {
						temp.i = telarr[arr[next.i][next.j] - 'A'][0].i;
						temp.j = telarr[arr[next.i][next.j] - 'A'][0].j;
					}
					if(!vis[temp.i][temp.j]){
						qu.push(temp);
//						vis[temp.i][temp.j] = 1;
					}
				} else {
					qu.push(next);
					vis[next.i][next.j] = 1;
				}
			}
		}
	}
	return -1;
}












