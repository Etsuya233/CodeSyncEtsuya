#include <iostream>
#include <cstring>
using namespace std;

typedef long long ll;
ll n, m;

ll dp[101][101][101];
ll moda = 1000000007;

ll dfs(ll mise, ll hana, ll osake);

int main(){
    memset(dp, -1, sizeof(dp));
    cin >> n >> m;
    dp[0][0][2] = 1;
    ll ans = dfs(n, m - 1, 1);
    cout << ans << "\n";
    return 0;
}

ll dfs(ll mise, ll hana, ll osake){
    if(osake > 100 || mise > 100 || hana > 100) return 0;
    if(mise < 0 || hana < 0 || osake < 0) return 0;
    if(dp[mise][hana][osake] != -1) return dp[mise][hana][osake];
    ll ret = 0;
    if(osake % 2 == 0) ret = (ret + dfs(mise - 1, hana, osake / 2)) % moda;
    ret = (ret + dfs(mise, hana - 1, osake + 1)) % moda;
    return dp[mise][hana][osake] = ret;
}