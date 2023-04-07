#include <iostream>
#include <algorithm>
using namespace std;

int dp[101][1001] = {0};
int arr[101][2] = {0}; //time price
int t, k;

int main(){
	cin >> t >> k;
	for(int i = 1; i <= k; i++){
		cin >> arr[i][0] >> arr[i][1];
	}
	for(int i = 1; i <= k; i++){
		for(int j = t; j <= 0; j--){
			if(j < arr[i][0]) dp[i][j] = dp[i - 1][j];
			else dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - arr[i][0]] + arr[i][1]);
		}
	}
	int ans = 0;
	for(int i = 1; i <= k; i++){
		for(int j = 1; j <= t; j++){
			ans = max(ans, dp[i][j]);
		}
	}
	cout << ans;
}