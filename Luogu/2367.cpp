#include <iostream>
#include <algorithm>
using namespace std;

int n, p;
int arr[5000050];
int dp[5000050];

int main(){
	cin >> n >> p;
	for(int i = 1; i <= n; i++){
		cin >> arr[i];
	}
	for(int i = 0; i < p; i++){
		int a, b, c;
		cin >> a >> b >> c;
		dp[a] += c;
		dp[b + 1] -= c;
	}
	for(int i = 2; i <= n; i++){
		dp[i] += dp[i - 1];
	}
	int ans = 0x7fffffff;
	for(int i = 1; i <= n; i++){
		arr[i] += dp[i];
		ans = min(arr[i], ans);
	}
	cout << ans;
	return 0;
}
