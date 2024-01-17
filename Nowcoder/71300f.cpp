#include <iostream>
#include <cmath>
using namespace std;

int n;
int arr[15];
int prime[1010];
int dp[15][30];
int ans = 0x7fffffff;
int vis[1010] = {0};

void primefind(int maxn);
void multi(int a);
void dfs(int layer, int sum);

int main(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> arr[i];
    }
	primefind(1000);
	for(int i = 1; i <= n; i++) multi(i);
	// for(int i = 1; i <= dp[1][0]; i++){
	// 	cout << dp[1][i] << " ";
	// }
	dfs(1, 0);
	cout << ((ans == 0x7fffffff)? -1: ans) << "\n";
	return 0;
}

void dfs(int layer, int sum){
	if(layer > n){
		ans = min(ans, sum);
		return;
	}
	if(sum > ans) return;
	for(int i = 1; i <= dp[layer][0]; i++){
		if(vis[dp[layer][i]] == 0){
			vis[dp[layer][i]] = 1;
			dfs(layer + 1, sum + dp[layer][i]);
			vis[dp[layer][i]] = 0;
		}
	}
}

void primefind(int maxn){
    int visa[1005] = {0};
    for(int i = 2; i <= maxn; i++){
        if(visa[i] == 0){
            prime[++prime[0]] = i;
        }
        for(int j = 1; j <= prime[0] && i * prime[j] <= maxn; j++){
            visa[i * prime[j]] = 1;
			if(i % prime[j] == 0) break;
        }
    }
}

void multi(int a){
	int num = arr[a];
	for(int i = 1; prime[i] <= num; i++){ //TODO 这里你改为sqrt看看对不对？？为啥对捏？？
		if(num % prime[i] == 0) dp[a][++dp[a][0]] = prime[i];
	}
}