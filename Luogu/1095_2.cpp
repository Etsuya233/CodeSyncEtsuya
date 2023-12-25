#include <iostream>
#include <algorithm>
using namespace std;

int main(){
	int m, s, t;
	int dp[2][1050] = {0};
	fill(dp[0], dp[0] + 2 * 1050, -1000000);
	cin >> m >> s >> t;
	dp[0][m] = 0;
	int ans = 0;
	int mint = 0x3fffffff;
	//init
	int nowt = 1;
	while(nowt <= t && m > 10){
		m -= 10;
		dp[nowt % 2][m] = 60 * nowt;
		ans = max(ans, dp[nowt % 2][m]);
		if(dp[nowt % 2][m] >= s) mint = min(mint, nowt);
		if(ans >= s) break;
		nowt++;
	}
	//dp
	if(ans < s){
		for(int i = nowt; i <= t; i++){
			for(int j = 0; j < 20; j++){
				dp[i % 2][j] = 0;
				dp[i % 2][j] = dp[(i - 1) % 2][j] + 17;
				if(j < 10) dp[i % 2][j] = max(dp[(i - 1) % 2][j + 10] + 60, dp[i % 2][j]);
				if(j >= 4) dp[i % 2][j] = max(dp[(i - 1) % 2][j - 4], dp[i % 2][j]);
				ans = max(ans, dp[i % 2][j]);
				if(dp[i % 2][j] >= s) mint = min(mint, i);
			}
			if(ans >= s) break;
		}
	}
	if(ans >= s) cout << "Yes\n" << mint;
	else cout << "No\n" << ans;
}
