#include <iostream>
#include <cstring>
using namespace std;

int n, m;
int moda = (int)1e9 + 7;
int dp[210][210][210] = {0};

int main(){
	cin >> n >> m;
	if(n == 1){
		cout << m + 1;
		return 0;
	}
	//init n = 2
	for(int i = 0; i <= m; i++){
		for(int j = 0; j <= m - i; j++){
			dp[2][j][i] = 1;
		}
	}
	//n >= 3
	int pre[210] = {0};
	for(int i = 3; i <= n; i++){
		for(int j = 0; j <= m; j++){
			//pre
			memset(pre, 0, sizeof(pre));
			pre[0] = dp[i - 1][0][j];
			for(int k = 1; k <= m - j; k++){
				pre[k] = (pre[k - 1] + dp[i - 1][k][j]) % moda;
			}
			for(int k = 0; k <= m - j; k++){
//				for(int l = 0; l <= m - k - j; l++){
//					dp[i][j][k] = (dp[i][j][k] + dp[i - 1][l][j]) % moda;
//				}
				dp[i][j][k] = pre[m - k - j];
//				cout << i << " " << j << " " << k << " " << dp[i][j][k] << endl;
			}
		}
	}
	int ans = 0;
	for(int i = 0; i <= m; i++){
		for(int j = 0; j <= m - i; j++){
			ans = (ans + dp[n][i][j]) % moda;
		}
	}
	cout << ans;
}
