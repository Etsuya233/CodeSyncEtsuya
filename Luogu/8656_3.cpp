#include <iostream>
#include <algorithm>
using namespace std;

int n, k;
int arr[100005] = {0};
int dp[100005] = {0};
int maxScore = 0;
int ans = 0;
int cnt = 0;

int main(){
	cin >> n >> k;
	for(int i = 0; i < n; i++){
		int a;
		cin >> a;
		if(arr[a] == 0) cnt++;
		arr[a]++;
		maxScore = max(maxScore, a);
	}
	if(k == 0){
		cout << cnt;
		return 0;
	}
	
	/*
	dp[i][j]：表示前i个物品，前j的背包容量，最大价值
	dp[i][j] = max(dp[i - 1][j], dp[i - 2 * k][j - arr[i]] + arr[i]);


	*/
	
	for(int i = 0; i <= maxScore; i++){
		for(int j = 10000; j >= 0; j--){
			dp[j] = max(dp[j], ((j - 2 * k >= 0)? dp[j - 2 * k]: 0) + arr[j]);
			ans = max(ans, dp[j]);
		}
	}
	
	cout << ans;
	return 0;
}
