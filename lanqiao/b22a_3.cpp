#include <iostream>
using namespace std;

typedef long long ll;

ll dp[2024][11][2024] = {0};

int main(){
    ll a = 10, b = 2022;
    dp[0][0][0] = 1;
    for(int i = 1; i <= b; i++){
        for(int j = 0; j <= a; j++){
            for(int k = 0; k <= b; k++){
                if(k - i >= 0 && j - 1 >= 0){
                    dp[i][j][k] += dp[i - 1][j - 1][k - i];
                }
                dp[i][j][k] += dp[i - 1][j][k];
            }
        }
    }
    cout << dp[b][a][b] << "\n";
    return 0;
}