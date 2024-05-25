#include <iostream>
#include <cstring>
using namespace std;

int moda = 1000000007;

int dp[2][6100][1500] = {0};

int main(){
    int d, t, m;
    cin >> d >> t >> m;
    dp[1][3100 - 1][1] = 1;
    if(d > 1) dp[1][3100 + 1][0] = 1;
    for(int i = 2; i <= t; i++){
        int ii = i % 2, li = (i + 1) % 2;
        memset(dp[ii], 0, sizeof(dp[ii]));
        for(int j = 3100 - i; j <= 3100 + i && j < 3100 + d; j++){
            for(int k = 0; k <= i && k <= m; k++){
                if(j + 1 < 3100 + d) dp[ii][j][k] = (dp[ii][j][k] + dp[li][j + 1][k - 1]) % moda;
                dp[ii][j][k] = (dp[ii][j][k] + dp[li][j - 1][k]) % moda;
                // if(dp[ii][j][k] != 0) cout << i << " " << j - 3100 << " " << k << ": " << dp[ii][j][k] << "\n";
            }
        }
    }
    int ans = 0;
    for(int i = 3100 - m; i < 3100 + d; i++){
        ans = (ans + dp[t % 2][i][m]) % moda;
    }
    cout << ans << "\n";
    return 0;
}