#include <iostream>
#include <algorithm>
using namespace std;

typedef struct CheckPaper{
	int date, val;
} che;

int days[13] = {0};
int increment[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
che checks[1005];
int dp[1005][5005] = {0};
int valid[1005] = {0};
int n, m, k;

bool cmpCheck(che a, che b){
	return a.date < b.date;
}

int main(){
	for(int i = 2; i <= 12; i++){
		days[i] = days[i - 1] + increment[i - 1];
	}
	checks[0].date = 0;
	checks[0].val = 0;
	cin >> n >> m >> k;
	for(int i = 1; i <= n; i++){
		int month, day;
		cin >> month >> day >> checks[i].val;
		checks[i].date = days[month] + day;
	}
	sort(checks + 1, checks + n + 1, cmpCheck);
	for(int i = 1; i <= n; i++){
		for(int j = 0; j <= i; j++){
			if(checks[i].date - checks[j].date >= k){
				valid[i] = j;
			} else {
				break;
			}
		}
	}
	for(int i = 1; i <= n; i++){
		for(int j = m; j >= checks[i].val; j--){
			dp[i][j] = max(dp[i - 1][j], dp[valid[i]][j - checks[i].val] + checks[i].val);
		}
	}
	cout << dp[n][m];
	return 0;
}
