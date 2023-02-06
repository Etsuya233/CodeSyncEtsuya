#include <iostream>
#include <algorithm>
using namespace std;

//row column
int n, m;
int arr[103][103] = {0};
int dp[103][103] = {0};
int xx[] = {0, 1, 0, -1};
int yy[] = {-1, 0, 1, 0};

int opera(int i, int j);
int check(int i, int j);

int main(){
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			cin >> arr[i][j];
		}
	}
	int ans = 0;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			ans = max(ans, opera(i, j));
		}
	}
	cout << ans;
}

int opera(int i, int j){
	if(dp[i][j] > 0) return dp[i][j];
	else {
		int temp;
		for(int a = 0; a < 4; a ++){
			if(check(i + yy[a], j + xx[a]) && arr[i][j] > arr[i + yy[a]][j + xx[a]]){
				temp = opera(i + yy[a], j + xx[a]);
				dp[i][j] = max(temp, dp[i][j]);
			}
		}
		return dp[i][j] = dp[i][j] + 1;
	}
}

int check(int i, int j){
	if(i > 0 && j > 0 && i <= n && j <= m) return 1;
	return 0;
}