#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

int arr[1005][1005] = {0};
int vis[1005][1005] = {0};
int arrtemp[1005][1005] = {0};
int ii[] = {-1, 0, 1, 0};
int jj[] = {0, -1, 0, 1};
int n;
int island1 = 1, island2 = 0;
int viss[1005] = {0};

void bfs(int iii, int jjj, int flag);

int main(){
	cin >> n;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			char a;
			cin >> a;
			if(a == '#') arrtemp[i][j] = arr[i][j] = 1;
		}
	}
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			if(arr[i][j] == 1 && vis[i][j] == 0){
				bfs(i, j, island1);
				island1 ++;
			}
		}
	}
	island1 --;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			for(int k = 0; k < 4; k++){
				if(arrtemp[i + ii[k]][j + jj[k]] == 0){
					arr[i][j] = 0;
					break;
				}
			}
		}
	}
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++)
			if(arr[i][j] != 0 && viss[arr[i][j]] == 0){
				viss[arr[i][j]] = 1;
				island2++;
			}
	}
	cout << island1 - island2;
}

void bfs(int iii, int jjj, int flag){
	queue<int> qi;
	queue<int> qj;
	qi.push(iii);
	qj.push(jjj);
	vis[iii][jjj] = 1;
	while(!qi.empty()){
		int nowi = qi.front();
		int nowj = qj.front();
		arr[nowi][nowj] = flag;
		qi.pop();
		qj.pop();
		for(int i = 0; i < 4; i++){
			if(nowi + ii[i] > 0 && nowi + ii[i] <= n && nowj + jj[i] > 0 && nowj + jj[i] <= n && vis[nowi + ii[i]][nowj + jj[i]] == 0 && arr[nowi + ii[i]][nowj + jj[i]] == 1){
				qi.push(nowi + ii[i]);
				qj.push(nowj + jj[i]);
				vis[nowi + ii[i]][nowj + jj[i]] = 1;
			}
		}
	}
}
