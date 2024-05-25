//#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int n;
double arr[100005] = {0};
double tr[100005] = {0};
double to[100005] = {0};
double dp[100005][2];

int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; i++){
		scanf("%lf", &arr[i]);
	}
	for(int i = 1; i <= n - 1; i++){
		scanf("%lf %lf", &tr[i], &to[i]);
	}
	if(n > 1){
		dp[1][0] = arr[1];
		dp[1][1] = arr[1] + tr[1] / 0.7;
		for(int i = 2; i <= n - 1; i++){
			dp[i][0] = min(dp[i - 1][0] + arr[i] - arr[i - 1], dp[i - 1][1] + to[i - 1] / 1.3);
			dp[i][1] = min(dp[i - 1][0] + arr[i] - arr[i - 1] + tr[i] / 0.7, dp[i - 1][1] + ((to[i - 1] >= tr[i])? ((to[i - 1] - tr[i]) / 1.3): ((tr[i] - to[i - 1]) / 0.7)));
		}	
		dp[n][0] = min(dp[n - 1][0] + arr[n] - arr[n - 1], dp[n - 1][1] + to[n - 1] / 1.3);	
	} else {
		dp[n][0] = arr[1];
	}
	printf("%.2f", dp[n][0]);
	return 0;
}
