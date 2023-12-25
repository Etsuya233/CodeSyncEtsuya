#include <iostream>
using namespace std;

int n;
int arr[205] = {0};
int dp[205][205] = {0};

int main(){
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> arr[i];
		arr[i + n] = arr[i];
	}
	arr[2 * n + 1] = arr[n];
	for(int d = 2; d <= n; d++){
		for(int i = 1; i <= 2 * n - d; i++){
			int j = i + d;
			for(int k = i + 1; k <= j - 1; k++){
				dp[i][j] = max(dp[i][j], dp[i][k] + dp[k][j] + arr[i] * arr[j] * arr[k]);
//				if(i == 4 && j == 7){
//					cout << k << "\t" << dp[i][k] << "\t" << dp[k][j] << "\t" << arr[i] * arr[j] * arr[k] << "\t" << dp[i][k] + dp[k][j] + arr[i] * arr[j] * arr[k]  << "\n";
//				}
			}
		}
	}
	int ans = 0;
	for(int i = 1; i <= n + 1; i++){
		ans = max(ans, dp[i][i + n]);
	}
	cout << ans << "\n";
	return 0;
}
