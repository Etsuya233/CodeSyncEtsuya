#include <iostream>
#include <cstring>
using namespace std;

char num[5005];
int n;
int ans = 0;
int dp[5005][5005] = {0};

int main(){
	cin >> num;
	n = strlen(num);
	//dp
	for(int i = 2; i <= n; i++){
		for(int j = 0; j < n; j++){
			if(j + i - 1 >= n) break;
			int lloc = j, rloc = j + i - 1;
			int l = num[lloc] - '0', r = num[rloc] - '0';
			if(l != r) dp[lloc][rloc] = l > r;
			else dp[lloc][rloc] = dp[lloc + 1][rloc - 1];
			if(dp[lloc][rloc] == 1) ans++;
		}
	}
	cout << ans << "\n";
	return 0;
}
