#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int t;
int arr[105];
bool dp[105][25005];
bool flag[25005];
int res = 0;

int main(){
	ios::sync_with_stdio(false);
	cin >> t;
	for(int p = 0; p < t; p++){
		int m;
		cin >> m;
		int maximum = 0;
		memset(dp, 0, sizeof(dp));
		for(int i = 0; i < m; i++){
			cin >> arr[i];
			dp[i][0] = true;
		}
		sort(arr, arr + m);
		maximum = arr[m - 1];
		//init
		res = 1;
		for(int i = arr[0]; i <= maximum; i += arr[0]){
			dp[0][i] = true;
		}
		//dp
		bool status;
		for(int i = 1; i < m; i++){
			bool entered = false;
			for(int j = 1; j <= maximum; j++){
				status = dp[i - 1][j];
				dp[i][j] = dp[i][j % arr[i]] || dp[i - 1][j] || j == arr[i];
				if(!entered && status != dp[i][j] && !flag[i]){
					flag[j] = true;
					res++;
					entered = true;
				}
			}
		}
		cout << res << endl;
	}

}