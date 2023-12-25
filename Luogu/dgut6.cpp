#include <iostream>
using namespace std;

typedef long long ll;

int dp[200][200] = {0};
int pre1[210] = {0};
int pre2[210] = {0};
int n, m;
int moda = (int)1e9 + 7;

int main(){
	cin >> n >> m;
	//init
	for(int i = 0; i <= m; i++) dp[1][i] = 1;
	pre1[0]= dp[1][0];
	for(int i = 1; i <= m; i++){
		pre1[i] = (pre1[i - 1] + dp[1][i]) % moda;
	}
	for(int i = 0; i <= m; i++){
		dp[2][i] = pre1[m - i];
	}
	//n >= 3
	for(int i = 3; i <= n; i++){
		pre2[0] = dp[i - 1][0] % moda;
		for(int j = 1; j <= m; j++){
			pre2[j] = (pre2[j - 1] + dp[i - 1][j]) % moda;
		}
		for(int j = 0; j <= m; j++){
			dp[i][0] = pre2[m] % moda;
			for(int k = 1; k <= m; k++){
				dp[i][k] = (((pre2[m] - pre2[k - 1] < 0)? pre2[m] + moda - pre2[k - 1]: pre2[m] - pre2[k - 1])) % moda;
			}
		}
	}
	int ans = 0;
	for(int i = 0; i <= m; i++){
		ans = (ans + dp[n][i]) % moda;
	}
//	for(int i = 0; i <= 200; i++){
//		cout << dp[200][i] << "\n";
//	}
	cout << ans;
	return 0;
}
