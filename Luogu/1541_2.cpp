#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
int arr[360] = {0};
int c[5] = {0};
int cc[150] = {0};
int vis[150] = {0};
int ans = 0;
int dp[40][40][40][40] = {0};

int main(){
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> arr[i];
	}
	for(int i = 1; i <= m; i++){
		int a;
		cin >> a;
		c[a] ++;
	}
	dp[0][0][0][0] = arr[1];
	ans = arr[1];
	int now = 1;
	for(int i = 0; i <= c[4]; i++){
		now += i * 4;
		for(int j = 0; j <= c[3]; j ++){
			now += j * 3;
			for(int k = 0; k <= c[2]; k++){
				now += k * 2;
				for(int l = 0; l <= c[1]; l++){
					now += l;
					
					if(i - 1 >= 0) dp[l][k][j][i] = max(dp[l][k][j][i], dp[l][k][j][i - 1] + arr[now]);
					if(j - 1 >= 0) dp[l][k][j][i] = max(dp[l][k][j][i], dp[l][k][j - 1][i] + arr[now]);
					if(k - 1 >= 0) dp[l][k][j][i] = max(dp[l][k][j][i], dp[l][k - 1][j][i] + arr[now]);
					if(l - 1 >= 0) dp[l][k][j][i] = max(dp[l][k][j][i], dp[l - 1][k][j][i] + arr[now]);
					ans = max(ans, dp[l][k][j][i]);
//					cout << l << " " << k << " " << j << " " << i << " " << dp[l][k][j][i] << "\n";
					
					now -= l;
				}
				now -= k * 2;
			}
			now -= j * 3;
		}
		now -= i * 4;
	}
	
	cout << ans;
	return 0;
}



