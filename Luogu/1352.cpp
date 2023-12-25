#include <iostream>
#include <vector>
#include <algorithm>
#define MAXN 0x3fffffff
using namespace std;

int n;
int arr[6005] = {0};
int pa[6005] = {0};
vector<int> ki[6005];
int dp[6005][2];

int dfs(int node, int status);

int main(){
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> arr[i];
	}
	for(int i = 1; i <= n - 1; i++){
		int a, b; //º¢×Ó ¸¸Ç×
		cin >> a >> b;
		pa[a] = b;
		ki[b].push_back(a);
	}
	//find root
	int ro = -1;
	for(int i = 1; i <= n; i++){
		if(pa[i] == 0){
			ro = i;
			break;
		}
	}
	//dfs
	fill(&dp[0][0], &dp[0][0] + 6005 * 2, MAXN);
	int ans1 = dfs(ro, 0);
	int ans2 = dfs(ro, 1);
	cout << max(ans1, ans2) << "\n";
	return 0;
}

int dfs(int node, int status){
	if(dp[node][status] != MAXN) return dp[node][status];
	int temp = 0;
	if(status == 1){
		for(int i = 0; i < ki[node].size(); i++){
			temp += dfs(ki[node][i], 0);
		}
		return dp[node][status] = temp + arr[node];
	} else {
		for(int i = 0; i < ki[node].size(); i++){
			temp += max(dfs(ki[node][i], 0), dfs(ki[node][i], 1));
		}
		return dp[node][status] = temp;
	}
}
