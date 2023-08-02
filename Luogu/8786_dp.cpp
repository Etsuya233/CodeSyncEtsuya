#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
int moda = 1000000007;
int dp[105][105][105];


int main(){
	cin >> n >> m;
	fill(dp[0][0], dp[0][0] + 105 * 105 * 105, 0); //memset
	dp[0][0][2] = 1;
	for(int i = 0; i <= n; i++){
		for(int j = 0; j <= m; j++){
			if(i == 0 && j == 0) continue;
			for(int k = 0; k <= m; k++){
				if(k % 2 == 0 && i > 0) dp[i][j][k] = dp[i - 1][j][k / 2];
				if(j > 0) dp[i][j][k] = (dp[i][j][k] + dp[i][j - 1][k + 1]) % moda;
			}
		}
	}
	cout << dp[n][m - 1][1]; //因为最后一次是花操作，如果输出dp[n][m][0]的话，就是最后一次啥操作都可以的数目。/
	return 0;
}

