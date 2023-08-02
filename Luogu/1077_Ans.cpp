#include <iostream>
using namespace std;

int n, m;
int arr[105];
int dp[105][105] = {0};
int moda = 1000007;
// int res = 0;

int dfs(int a, int now);

int main(){
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> arr[i];
    }
    int ret = dfs(1, 0);
    cout << ret;
}

int dfs(int a, int now){
    if(now > m) return 0;
    if(now == m) return 1;
    if(a == n + 1) return 0; //这里已经包含上面的条件了
    if(dp[a][now] == 0){
        for(int i = 0; i <= arr[a]; i++){
            dp[a][now] = (dfs(a + 1, now + i) + dp[a][now]) % moda;
        }
    }
    return dp[a][now] % moda;
}