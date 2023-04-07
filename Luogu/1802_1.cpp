#include <iostream>
#include <algorithm>
using namespace std;

typedef struct People{
	int lose, win, use;
} pp;

int n, x, ans = 0;
pp arr[1001];
long long dp[1001] = {0};

int main(){
	cin >> n >> x;
	for(int i = 1; i <= n; i++) cin >> arr[i].lose >> arr[i].win >> arr[i].use;
	for(int i = 1; i <= n; i++){
		for(int j = x; j >= 1; j--){
			if(j >= arr[i].use) dp[j] = (dp[j - arr[i].use] + arr[i].win > dp[j] + arr[i].lose)? dp[j - arr[i].use] + arr[i].win: dp[j] + arr[i].lose;
			else dp[j] += arr[i].lose;
		}
	}
	cout << dp[x] * 5;
}

/*
理解：
① 这个是背包问题，因为前面的结果一定会决定了后面的结果。
② 最优化：
	打不过就直接认输，这样子就不会浪费药水。
	可以打赢的话，在药水一定的情况下，不一定打赢的情况最好，所以要分打赢和让步的情况。
③ 问题：
	
*/