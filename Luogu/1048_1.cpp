#include <iostream>
#include <algorithm>
using namespace std;

int main(){
	int n, M, T;
	int m[202] = {0}, t[202] = {0};
	int dp[202][202] = {0};
	cin >> n >> M >> T;
	for(int i = 1; i <= n; i++){
		cin >> m[i] >> t[i];
	}
	for(int i = 1; i <= n; i++){
		for(int j = M; j >= m[i]; j--){
			for(int k = T; k >= t[i]; k--){
				dp[j][k] = max(dp[j - m[i]][k - t[i]] + 1, dp[j][k]);
			}
		}
	}
	cout << dp[M][T];
	return 0;
}
