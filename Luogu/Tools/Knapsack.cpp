#include <iostream>
#include <algoritm>
using namespace std;

/*
1：
n个物品：重量为w，价值为v
一个背包：体积为vol
求能取到的最大价值？
2：
利用有限的总资源，合理选取需要消耗资源的对象，以达到最大的总收益？
*/

int n = 10, vol = 100, w[1000], v[1000];
int dp[1000][1000], dps[1000];

int main(){
	//0-1
	for(int i = 0;
	 < n; i++){
		for(int j = 0; j < vol; j++){
			dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w[i]] + v[i]);
		}
	}
	//0-1 Simplified
	for(int i = 0; i < n; i++){
		for(int j = 0; j < vol; j++){
			dps[j] = max(dps[j], dps[j - w[i]] + v[i]);
		}
	}
}
