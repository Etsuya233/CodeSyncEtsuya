#include <iostream>
using namespace std;

int n = 30;
int dp[35][105] = {0};

int main(){
	dp[1][0] = 1;
	dp[1][10] = 1; 
	//dp[i + 1][j + 10] += dp[i][j]; dp[i + 1][0] += dp[i][j];
	for(int i = 1; i <= 29; i++){
		for(int j = 0; j <= 100; j++){
			if(j + 10 <= 99) dp[i + 1][j + 10] += dp[i][j];
			dp[i + 1][0] += dp[i][j];
		}
	}
	int ans = 0;
	for(int i = 1; i <= 30; i++){
		ans += dp[i][70];
	}
	cout << ans << "\n";
	return 0;
}
