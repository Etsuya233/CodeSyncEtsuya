#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
int w[70][3], v[70][3];
int isPri[70] = {0};
int child[70] = {0};
int dp[320005] = {0};

int calc(int i, int j);

int main(){
    /*
	遍历：按主键遍历i，背包遍历j，配件遍历k
		1，不买这个主键（也不买配件）
		2，买这个主键但是不买配件
		3，买主键且买配件1
		4，买主键且买配件2
		5，买主键且买配件1，2	
	*/
	cin >> n >> m;
	for(int i = 1; i <= m; i++){
		int ww, vv, gg;
		cin >> ww >> vv >> gg;
		if(!gg){
			w[i][0] = ww;
			v[i][0] = vv;
			isPri[i] = 1;
		} else {
			child[gg]++;
			w[gg][child[gg]] = ww;
			v[gg][child[gg]] = vv;
		}
	}
	for(int i = 0; i <= m; i++){
		if(!isPri[i]) continue;
		for(int j = n; j >= w[i][0]; j--){
			//1 不买这个主键
			//2 买这个主键
			dp[j] = max(dp[j], dp[j - w[i][0]] + calc(i, 0));
			//3 买配件1
			if(child[i] >= 1 && j - w[i][0] - w[i][1] >= 0)
				dp[j] = max(dp[j], dp[j - w[i][0] - w[i][1]] + calc(i, 0) + calc(i, 1));
			//4 买配件2
			if(child[i] >= 2 && j - w[i][0] - w[i][2] >= 0)
				dp[j] = max(dp[j], dp[j - w[i][0] - w[i][2]] + calc(i, 0) + calc(i, 2));
			//5 配件1 2都买
			if(child[i] >= 2 && j - w[i][0] - w[i][1] - w[i][2] >= 0)
				dp[j] = max(dp[j], dp[j - w[i][0] - w[i][1] - w[i][2]] + calc(i, 0) + calc(i, 1) + calc(i, 2));
		}
	}
	cout << dp[n];
}

int calc(int i, int j){
	return w[i][j] * v[i][j];
}