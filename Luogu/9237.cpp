#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int n, m;
int arr[15][15] = {0};
int dp[15][15] = {0};
int vis[15][15] = {0};
int k = 0;
int ki[105] = {0}, kj[105] = {0};
int endou = 0;

void dfs(int ii, int jj);

int main(){
	cin >> n >> m;
	memset(arr, -1, sizeof(arr));
	memset(vis, -1, sizeof(vis));
	for(int i = 1; i <= n; i++){
		char temp[15];
		cin >> temp;
		for(int j = 0; j < m; j++){
			if(temp[j] != '_'){
				vis[i][j + 1] = arr[i][j + 1] = temp[j] - '0';
				ki[k] = i;
				kj[k] = j + 1;
				k++;
			}
		}
	}
	dfs(1, 1);
	return 0;
}

void dfs(int ii, int jj){
//	for(int i = 1; i <= n; i++){
//		for(int j = 1; j <= m; j++){
//			cout << dp[i][j] << " ";
//		}
//		cout << "\n";
//	}
//	cout << "\n";
	//final answer 
	if(ii == n + 1){
		if(ii >= n - 1 && jj == 1){
			for(int a = 0; a < k; a++){
				if(ki[a] >= ii - 2){
					int iii = ki[a], jjj = kj[a];
					int cnt = 0;
					for(int i = -1; i <= 1; i++){
						for(int j = -1; j <= 1; j++){
							cnt += dp[iii + i][jjj + j];
						}
					}
					if(cnt != arr[iii][jjj]) return;
				} else if(ki[a] < ii - 2) {
					continue;
				}
			}
		}
		endou = 1;
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= m; j++){
				cout << dp[i][j];
			}
			cout << "\n";
		}
		return;
	}
	//inspect
	if(ii >= 2 && jj >= 3){
		int isi = ii - 1, isj = jj - 2;
		if(arr[isi][isj] != -1){
			int cnt = 0;
			for(int i = -1; i <= 1; i++){
				for(int j = -1; j <= 1; j++){
					cnt += dp[isi + i][isj + j];
				}
			}
			if(cnt != arr[isi][isj]) return;
		}
	}
	if(ii >= 3 && jj == 1){
		int isi = ii - 2, isj = m - 1;
		if(arr[isi][isj] != -1){
			int cnt = 0;
			for(int i = -1; i <= 1; i++){
				for(int j = -1; j <= 1; j++){
					cnt += dp[isi + i][isj + j];
				}
			}
			if(cnt != arr[isi][isj]) return;
		}
		isj ++;
		if(arr[isi][isj] != -1){
			int cnt = 0;
			for(int i = -1; i <= 1; i++){
				for(int j = -1; j <= 1; j++){
					cnt += dp[isi + i][isj + j];
				}
			}
			if(cnt != arr[isi][isj]) return;
		}
	}
//	dfs
	int nextj = (jj == m)? 1: jj + 1;
	int nexti = (nextj == 1)? ii + 1: ii;
	dp[ii][jj] = 0;
	dfs(nexti, nextj);
	for(int i = -1; i <= 1; i++){
		for(int j = -1; j <= 1; j++){
			if(arr[ii + i][jj + j] != -1 && vis[ii + i][jj + j] >= 1){
				vis[ii + i][jj + j] -= 1;
			}
		}
	}
	dp[ii][jj] = 1;
	dfs(nexti, nextj);
	if(endou == 1) return;
	for(int i = -1; i <= 1; i++){
		for(int j = -1; j <= 1; j++){
			if(arr[ii + i][jj + j] != -1){
				vis[ii + i][jj + j] += 1;
			}
		}
	}	
}
