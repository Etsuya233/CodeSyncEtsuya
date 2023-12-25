#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int t;
int n;
int m;
int arr1[105];
int arr2[105];
int dp[102][25002];

int main(){
	cin >> t;
	while(t--){
		cin >> n;
		m = 0;
		for(int i = 1; i <= n; i++){
			cin >> arr1[i];
		}
		sort(arr1 + 1, arr1 + n + 1);
		//dp
		memset(dp, 0, sizeof(dp));
		for(int i = 1; i <= n; i++){
			dp[i][0] = 1;
			for(int j = 1; j < arr1[i]; j++) dp[i][j] = dp[i - 1][j];
			for(int j = arr1[i]; j <= arr1[n]; j++){
				dp[i][j] = dp[i - 1][j] || dp[i][j - arr1[i]];
//				cout << i << " " << j << " " <<  dp[i - 1][j] << dp[i][j - arr1[i]] << "\n";
			}
		}
		//travel
		for(int i = 1; i <= n; i++){
			if(!dp[i - 1][arr1[i]]){
				arr2[++m] = arr1[i];
			}
		}
		cout << m << "\n";
	}
	return 0;
}
