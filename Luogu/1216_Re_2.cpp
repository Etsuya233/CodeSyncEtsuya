#include <iostream>
#include <algorithm>
using namespace std;

int dp[1005] = {0};
int arr[1005] = {0};
int r, ans = 0;

int main(){
	cin >> r;
	cin >> dp[1];
	for(int i = 2; i <= r; i++){
		for(int j = 1; j <= i; j++){
			cin >> arr[j];
		}
		for(int j = i; j >= 1; j--){
			dp[j] = arr[j] + max(dp[j], dp[j - 1]);
			ans = max(ans, dp[j]);
		}
//		for(int j = 1; j <= i; j++){
//			cout << dp[j] << " ";
//		}
//		cout << "\n";
	}
	cout << ans;
	return 0;
}
