#include <iostream>
#include <queue>
#include <cmath>
using namespace std;

typedef long long ll;

typedef struct Position{
	ll i, j, t;
} po;

ll ii[4] = {0, 1, 0, -1};
ll jj[4] = {1, 0, -1, 0};
ll n, m, t, cnt = 0;
ll si, sj, di, dj;
char arr[205][205];
ll dp[205][205][15] = {0};

void bfs();

int main(){
	cin >> n >> m >> t;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			cin >> arr[i][j];
		}
	}
	cin >> si >> sj >> di >> dj;
	bfs();
	cout << dp[di][dj][t];
	return 0;
}

void bfs(){
	dp[si][sj][0] = 1;
	ll nexti, nextj;
	for(int tt = 1; tt <= t; tt++){
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= m; j++){
				if(tt == 15 && i == 18 && j == 10){
					int cntt = 0;
					cout << dp[i][j][tt] << "\n";
					for(int k = 0; k < 4; k++){
						nexti = i + ii[k];
						nextj = j + jj[k];
						if(nexti >= 1 && nexti <= n && nextj >= 1 && nextj <= m && arr[nexti][nextj] != '*'){
							cout << dp[nexti][nextj][tt - 1];
							cntt += dp[nexti][nextj][tt - 1];
							cout << " " << cntt << "\n";
							dp[i][j][tt] += dp[nexti][nextj][tt - 1];
						}
					}
				} else {
					for(int k = 0; k < 4; k++){
						nexti = i + ii[k];
						nextj = j + jj[k];
						if(nexti >= 1 && nexti <= n && nextj >= 1 && nextj <= m && arr[nexti][nextj] != '*'){
							dp[i][j][tt] += dp[nexti][nextj][tt - 1];
						}
					}
				}
			}
		}
//		for(int i = 1; i <= n; i++){
//			for(int j = 1; j <= m; j++){
//				cout << dp[i][j][tt] << " ";
//			}
//			cout << " \n";
//		}
//		cout << "\n";
	}
}







