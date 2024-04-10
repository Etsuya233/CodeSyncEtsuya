#include <iostream>
using namespace std;

typedef long long ll;

ll dp[35][35] = {0};

int main(){
    ll n, m;
    cin >> n >> m;
    dp[0][1] = 1;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(i % 2 == 0 && j % 2 == 0) continue;
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        }
    }
    cout << dp[n][m] << "\n";
    return 0;
}