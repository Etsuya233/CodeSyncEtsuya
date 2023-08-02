#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int n, m;
int card[5] = {0};
int point[352] = {0};
int dp[41][41][41][41] = {0};

int dfs(int n1, int n2, int n3, int n4);


int main(){
    memset(dp, -1, sizeof(dp));
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> point[i];
    }
    for(int i = 0; i < m; i++){
        int a;
        cin >> a;
        card[a] ++;
    }
    dp[0][0][0][0] = point[1];
    cout << dfs(card[1], card[2], card[3], card[4]);
}

int dfs(int n1, int n2, int n3, int n4){
    if(dp[n1][n2][n3][n4] != -1) return dp[n1][n2][n3][n4];
    else {
        int ret = 0;
        int dis = n1 * 1 + n2 * 2 + n3 * 3 + n4 * 4;
        if(n1 - 1 >= 0) ret = max(ret, dp[n1 - 1][n2][n3][n4] + point[dis]);
        if(n2 - 1 >= 0) ret = max(ret, dp[n1][n2 - 1][n3][n4] + point[dis]);
        if(n3 - 1 >= 0) ret = max(ret, dp[n1][n2][n3 - 1][n4] + point[dis]);
        if(n4 - 1 >= 0) ret = max(ret, dp[n1][n2][n3][n4 - 1] + point[dis]);
        return dp[n1][n2][n3][n4] = ret;
    }
}