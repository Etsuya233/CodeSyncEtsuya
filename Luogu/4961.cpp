#include <iostream>
#include <queue>
using namespace std;

int n, m;
int arr[1005][1005] = {0};
int mapa[1005][1005] = {0};
int vis[1005][1005] = {0};
int ii[8] = {0, 1, 0, -1, -1, 1, 1, -1};
int jj[8] = {1, 0, -1, 0, -1, 1, -1, 1};
int mapb[1005][1005] = {0};
int cnt1 = 0;
int cnt2 = 0;

void bfs(int iii, int jjj);

int main(){
	cin >> n >> m;
	//find number
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			int a;
			cin >> a;
			if(a == 1){
				arr[i][j] ++;
				mapa[i - 1][j - 1]++;
				mapa[i + 2][j + 2]++;
				mapa[i - 1][j + 2]--;
				mapa[i + 2][j - 1]--;
			}
		}
	}
	//pre number
	for(int i = 1; i <= m; i++) mapa[0][i] += mapa[0][i - 1];
	for(int i = 1; i <= n; i++){
		mapa[i][0] += mapa[i - 1][0];
		for(int j = 1; j <= m; j++){
			mapa[i][j] += (mapa[i - 1][j] + mapa[i][j - 1] - mapa[i - 1][j - 1]);
		}
	}
	//find block
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			if(!mapa[i][j] && !vis[i][j]){
				cnt1++;
				bfs(i, j);
			}
		}
	}
	//pre and find special
	for(int i = 1; i <= m; i++) mapb[0][i] += mapb[0][i - 1];
	for(int i = 1; i <= n; i++){
		mapb[i][0] += mapb[i - 1][0];
		for(int j = 1; j <= m; j++){
			mapb[i][j] += (mapb[i - 1][j] + mapb[i][j - 1] - mapb[i - 1][j - 1]);
			if(!arr[i][j] && !mapb[i][j]){
//				cout << i << " " << j << "\n";
				cnt2++;
			}
		}
	}
	cout << cnt1 + cnt2;
	return 0;
}

void bfs(int iii, int jjj){
	queue<int> qui;
	queue<int> quj;
	qui.push(iii);
	quj.push(jjj);
	while(!qui.empty()){
		int nowi = qui.front();
		qui.pop();
		int nowj = quj.front();
		quj.pop();
		vis[nowi][nowj] = 1;
		mapb[nowi - 1][nowj - 1]++;
		mapb[nowi + 2][nowj + 2]++;
		mapb[nowi - 1][nowj + 2]--;
		mapb[nowi + 2][nowj - 1]--;
		for(int i = 0; i < 8; i++){
			int nexti = nowi + ii[i];
			int nextj = nowj + jj[i];
			if(!vis[nexti][nextj] && !mapa[nexti][nextj] && nexti >= 1 && nexti <= n && nextj >= 1 && nextj <= m){
				qui.push(nexti);
				quj.push(nextj);
				vis[nexti][nextj] = 1;
			}
		}
	}
}
