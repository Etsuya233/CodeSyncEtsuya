#include <iostream>
using namespace std;

int m, n;
int price[101];
int dp[101][10001] = {0};

int main(){
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> price[i];
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(price[i] == j) dp[i][j] = dp[i - 1][j] + 1;
            else if(price[i] < j) dp[i][j] = dp[i - 1][j];
            else dp[i][j] = dp[i - 1][j] + dp[i - 1][j - price[i]];
        }
    }
    cout << dp[n][m];
}