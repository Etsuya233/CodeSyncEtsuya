#include <iostream>
using namespace std;

typedef long long ll;

ll dp[2][2025][2025] = {0};

int main(){
    ll a = 10, b = 2022;
    for(int i = 1; i <= b; i++){
        dp[1][i][i] = 1;
    }
    for(int i = 2; i <= a; i++){
        int ni = i % 2, la = (i + 1) % 2;
        for(int j = 1; j <= b; j++){
            cout << i << " " << j << "\n";
            for(int k = 1; k <= j; k++){
                for(int j1 = 1; j1 <= j; j1++){
                    for(int k1 = 1; k1 <= j - j1; k1++){
                        dp[ni][j][k] += dp[la][j1][k1];
                    }
                }
            }
            
        }
    }
    ll ans = 0;
    for(int i = 1; i <= b; i++){
        ans += dp[a][b][i];
    }
    cout << ans << "\n";
}