#include <iostream>
#include <algorithm>
using namespace std;

typedef struct Shopping{
	int v, w, fa = 0, so1 = 0, so2 = 0, soNum = 0;
} sh;

int n, m;
sh arr[62]; //main ac1 ac2 amount
int dp[2][32005][4] = {0}; //main main+ac1 main+ac2 all
int ans = 0;

int main(){
	cin >> n >> m;
	for(int i = 1; i <= m; i++){
		int a, b, c;
		cin >> a >> b >> c;
		arr[i].v = a * b;
		arr[i].w = a;
		if(c != 0){
			arr[i].fa = c;
			if(arr[c].soNum == 0){
				arr[c].so1 = i;
			} else arr[c].so2 = i;
			arr[c].soNum ++;
		}
	}
	int rectify = 0; //减少是附属物件时的复制数组次数
	for(int i = 1; i <= m; i++){
		if(arr[i].fa != 0){
			rectify ++;
			continue;
		}
		int ii = (i - rectify) % 2;
		//copy
		for(int j = 0; j <= n; j++){
			int maxval = max(dp[(ii + 1) % 2][j][0], max(dp[(ii + 1) % 2][j][1], max(dp[(ii + 1) % 2][j][2], dp[(ii + 1) % 2][j][3])));
			for(int k = 0; k < 4; k++){
				dp[ii][j][k] = maxval;;
			}
		}
		//main
		for(int j = arr[i].w; j <= n; j++){
			for(int k = 0; k < 4; k++){
				dp[ii][j][0] = max(dp[(ii + 1) % 2][j][k], dp[(ii + 1) % 2][j - arr[i].w][k] + arr[i].v);
				ans = max(ans, dp[ii][j][0]);
			}
		}
		//ac1
		if(arr[i].soNum >= 1){
			for(int j = arr[i].w + arr[arr[i].so1].w; j <= n; j++){
				for(int k = 0; k < 4; k++){
					dp[ii][j][1] = max(dp[(ii + 1) % 2][j][k], dp[(ii + 1) % 2][j - arr[i].w - arr[arr[i].so1].w][k] + arr[i].v + arr[arr[i].so1].v);
					ans = max(ans, dp[ii][j][1]);
				}
			}
		}
		//ac2
		if(arr[i].soNum >= 2){
			for(int j = arr[i].w + arr[arr[i].so2].w; j <= n; j++){
				for(int k = 0; k < 4; k++){
					dp[ii][j][2] = max(dp[(ii + 1) % 2][j][k], dp[(ii + 1) % 2][j - arr[i].w - arr[arr[i].so2].w][k] + arr[i].v + arr[arr[i].so2].v);
					ans = max(ans, dp[ii][j][2]);
				}
			}
		}
		//all
		if(arr[i].soNum >= 2){
			for(int j = arr[i].w + arr[arr[i].so2].w + arr[arr[i].so1].w; j <= n; j++){
				for(int k = 0; k < 4; k++){
					dp[ii][j][3] = max(dp[(ii + 1) % 2][j][k], dp[(ii + 1) % 2][j - arr[i].w - arr[arr[i].so2].w - arr[arr[i].so1].w][k] + arr[i].v + arr[arr[i].so2].v + arr[arr[i].so1].v);
					ans = max(ans, dp[ii][j][3]);
				}
			}
		}
	}
	cout << ans;
}
