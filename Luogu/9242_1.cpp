#include <iostream>
#include <algorithm>
using namespace std;

int main(){
	int n;
	int dp[10] = {0};
	cin >> n;
	for(int i = 0; i < n; i++){
		int now;
		cin >> now;
		int t = now % 10;
		int h = t;
		while(now > 0){
			h = now % 10;
			now /= 10;
		}
		dp[t] = max(dp[t], dp[h] + 1);
	}
	int ans = -1;
	for(int i = 0; i <= 9; i++) ans = max(ans, dp[i]);
	cout << n - ans << "\n";
	return 0;
}
