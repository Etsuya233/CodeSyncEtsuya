#include <iostream>
#include <algorithm>
using namespace std;

int s, n, m;
int dp[20002] = {0};
int sol[102][102] = {0};
int ans = 0;

int main(){
	cin >> s >> n >> m;
	//sol input
	for(int i = 1; i <= s; i++){
		for(int j = 1; j <= n; j++){
			int a;
			cin >> a;
			sol[j][i] = a; //第j个城堡，第i个人派了那么多个人
		}
	}
	//dp
	for(int i = 1; i <= n; i++){
  		for(int j = m; j >= 0; j--){
			sort(&sol[i][0] + 1, &sol[i][0] + s + 1);
			for(int k = 1; k <= s; k++){
				if(j - sol[i][k] * 2 - 1 >= 0) dp[j] = max(dp[j], dp[j - sol[i][k] * 2 - 1] + i * k);
			}
			ans = max(ans, dp[j]);
		}
	}
	//cout
	cout << ans << "\n";
	return 0;
}
