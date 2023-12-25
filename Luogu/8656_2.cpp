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
	for(int i = 0; i < k; i++){
		dp[i] = arr[i];
		dp[i + k] = max(arr[i], arr[i + k]);
		int j = i + 2 * k;
		for( ; j <= maxScore; j += k){
			dp[j] = max(dp[j - k], dp[j - 2 * k] + arr[j]);
		}
		ans += dp[j - k];
	}
	cout << ans;
	return 0;
}
