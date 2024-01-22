#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

typedef long long ll;

ll n, m;
ll dp[101][101][101] = {0};
ll ans = 0;

ll moda = 1000000007;

ll dfs(ll osake, ll mise, ll hana, ll layer);

int main(){
    memset(dp, -1, sizeof(dp));
    dp[2][0][0] = 1;
    cin >> n >> m;
    // 初始化数组为0
    // for(int j = 0; j <= n; j++){
    //     for(int k = 0; k <= m; k++){
    //         if(j == 0 && k == 0) continue;
    //         for(int i = 0; i <= m; i++){//osake mise hana
    //             if(i % 2 == 0 && j > 0) dp[i][j][k] = dp[i / 2][j - 1][k];
    //             if(k > 0) dp[i][j][k] = (dp[i][j][k] + dp[i + 1][j][k - 1]) % moda;
    //         }
    //     }
    // }
    cout << dfs(1, n, m - 1, 0) << "\n";
    cout << dp[1][n][m - 1] << "\n";
    return 0;
}

//TODO why???
ll dfs(ll osake, ll mise, ll hana, ll layer){
    if(osake > 100 || mise > 100 || hana > 100) return 0;
    if(osake < 0 || mise < 0 || hana < 0) return 0;
    if(dp[osake][mise][hana] != -1) return dp[osake][mise][hana];
    ll ret = 0;
    if(hana > 0) ret += dfs(osake + 1, mise, hana - 1, layer  + 1) % moda; //hana
    if((osake % 2 == 0) && mise > 0) ret = (ret + dfs(osake / 2, mise - 1, hana, layer + 1) % moda) % moda; //mise
    cout << osake << " " << mise << " " << hana << " " << layer << " " << ret << "\n";
    return dp[osake][mise][hana] = ret;
}