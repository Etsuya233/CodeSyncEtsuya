#include <iostream>
#include <algorithm>
using namespace std;

int n;
int arr[101][101] = {0};
int dp[101][101] = {0};

int opera(int i, int j);

int main(){
	cin >> n;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= i; j++){
			cin >> arr[i][j];
		}
	}
	int ans = opera(1, 1);
	cout << ans;
}

int opera(int i, int j){
	if(i > n) return 0;
	if(dp[i][j] > 0) return dp[i][j];
	else {
		int a = (dp[i + 1][j] > 0)? dp[i + 1][j]: (dp[i + 1][j] = opera(i + 1, j));
		int b = (dp[i + 1][j + 1] > 0)? dp[i + 1][j + 1]: (dp[i + 1][j + 1] = opera(i + 1, j + 1));
		return dp[i][j] = max(a, b) + arr[i][j];
	}
}