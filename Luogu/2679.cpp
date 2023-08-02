#include <iostream>
using namespace std;

int n, m, k, simplier = 1000000007;
int dp[2][202][202][2];
char a[1005], b[205];

int main(){
	ios::sync_with_stdio(false);
	//ai == bj
	//dp[i][j][k][1] = dp[(i - 1) % 2][j - 1][k][1]  +  dp[(i - 1) % 2][j - 1][k - 1][0]
	//                     + ?dp[(i - 1) % 2][j - 1][k - 1][1]?
	//       参与   上一次未结束字串黏在一起  新串从这个字母开始 新串但是使用之前的字母
	//dp[i][j][k][0] =  dp[(i - 1) % 2][j][k][0] + dp[(i - 1) % 2][j][k][1]
	//       不参与
	//ai != bj
	//dp[i][j][k][0] = dp[(i - 1) % 2][j][k][0] + dp[(i - 1) % 2][j][k][1]
	//dp[i][j][k][1] = 0
	//关系：+?  A串前i个字符中的一些字符构成B串前j个字符用了k个字串

	cin >> n >> m >> k;
	cin >> (a + 1) >> (b + 1);
	//Initialize
	dp[0][0][0][0] = 1;
	dp[1][0][0][0] = 1;
	//DP
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= min(m, i); j++){
			for(int c = 1; c <= min(j, k); c++){
				if(a[i] == b[j]){
					dp[i % 2][j][c][1] = ((dp[(i - 1) % 2][j - 1][c][1]  +  dp[(i - 1) % 2][j - 1][c - 1][0]) % simplier + dp[(i - 1) % 2][j - 1][c - 1][1]) % simplier;
					dp[i % 2][j][c][0] =  (dp[(i - 1) % 2][j][c][0] + dp[(i - 1) % 2][j][c][1]) % simplier;
				} else {
					dp[i % 2][j][c][0] = (dp[(i - 1) % 2][j][c][0] + dp[(i - 1) % 2][j][c][1]) % simplier;
					dp[i % 2][j][c][1] = 0;
				}
			}
		}
	}
	//Output
	cout << (dp[n % 2][m][k][0] + dp[n % 2][m][k][1]) % simplier;
}