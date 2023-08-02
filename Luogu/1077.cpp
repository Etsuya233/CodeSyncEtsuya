#include <iostream>
#include <cstring>
using namespace std;

int n, m;
int arr[105];
int dp[105][105] = {0};
int moda = 1000007;

int dfs(int a, int now);

int main(){
    memset(dp, -1, sizeof(dp));
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> arr[i];
    }
    int ret = dfs(1, 0);
    cout << ret;
}

int dfs(int a, int now){
    if(a == n + 1){
        if(now == m) return 1;
        else return 0;
    }
    if(dp[a][now] == -1){
        dp[a][now] = 0;
        for(int i = 0; i <= arr[a]; i++){
            dp[a][now] = (dfs(a + 1, now + i) + dp[a][now]) % moda;
        }
    }   
    return dp[a][now] % moda;
}