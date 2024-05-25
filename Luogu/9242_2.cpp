#include <iostream>
using namespace std;

int dp[10] = {0};

int main(){
	int n;
	cin >> n;
	for(int i = 1; i <= n; i++){
		int a;
		cin >> a;
		int h, t;
		t = a % 10;
		while(a > 0){
			h = a % 10;
			a /= 10;
		}
		dp[t] = max(dp[t], dp[h] + 1);
	}
	int ans = 0;
	for(int i = 0; i <= 9; i++){
		ans = max(ans, dp[i]);
	}
	cout << n - ans << "\n";
	return 0;
}
