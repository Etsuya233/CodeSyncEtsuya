#include <iostream>
using namespace std;

typedef long long ll;
ll arr[505][505] = {0};
ll n, m, kk;
ll dp[505][505] = {0};
ll ans = 0;

int main(){
    ios::sync_with_stdio(false);
    cin >> n >> m >> kk;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> arr[i][j];
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1] + arr[i][j] - dp[i - 1][j - 1];
        }
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){ //starter
            for(int k = i; k <= n; k++){
                for(int l = j; l <= m; l++){
                    if(dp[k][l] - dp[k][j - 1] - dp[i - 1][l] + dp[i - 1][j - 1] > kk){
                        break;
                    }
                    ans ++;
                }
            }
        }
    }
    cout << ans << "\n";
    return 0;
}