#include <iostream>
#include <algorithm>
using namespace std;

typedef struct Shopping{
	int v, w, fa = 0, so1 = 0, so2 = 0, soNum = 0;
} sh;

int n, m;
sh arr[62]; //main ac1 ac2 amount
int dp[2][32005] = {0}; //main main+ac1 main+ac2 all
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

	int rectify = 0;
	for(int i = 1; i <= m; i++){
		if(arr[i].fa != 0){
			rectify ++;
			continue;
		}
		int ii = (i - rectify) % 2;

  		for (int j = 0; j <= n; j++) {
  			dp[ii][j] = dp[(ii + 1) % 2][j];
            if (j >= arr[i].w) dp[ii][j] = max(dp[(ii + 1) % 2][j], dp[(ii + 1) % 2][j - arr[i].w] + arr[i].v);
            if (arr[i].soNum >= 1 && j >= arr[i].w + arr[arr[i].so1].w) {
                dp[ii][j] = max(dp[ii][j], dp[(ii + 1) % 2][j - arr[i].w - arr[arr[i].so1].w] + arr[i].v + arr[arr[i].so1].v);
            }
            if (arr[i].soNum >= 2 && j >= arr[i].w + arr[arr[i].so2].w) {
                dp[ii][j] = max(dp[ii][j], dp[(ii + 1) % 2][j - arr[i].w - arr[arr[i].so2].w] + arr[i].v + arr[arr[i].so2].v);
            }
            if (arr[i].soNum >= 2 && j >= arr[i].w + arr[arr[i].so2].w + arr[arr[i].so1].w) {
                dp[ii][j] = max(dp[ii][j], dp[(ii + 1) % 2][j - arr[i].w - arr[arr[i].so1].w - arr[arr[i].so2].w] + arr[i].v + arr[arr[i].so1].v + arr[arr[i].so2].v);
            }
            ans = max(ans, dp[ii][j]);
        }
	}
	cout << ans;


}
