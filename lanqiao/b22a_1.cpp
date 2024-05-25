#include <iostream>
using namespace std;

typedef long long ll;
ll dp[11][2025] = {0}; //用i个不同的数字，组成j的方法数，组成的最大数字为k.

int main(){
    ll a = 10, b = 2022;
    for(ll i = 1; i <= b; i++) dp[1][i] = 1;
    for(ll j = 1; j <= b; j++){ 
        for(ll k1 = 1; k1 <= j; k1++){
            ll k2 = j - k1;
            if(k1 >= k2) break; 
            dp[2][j] += dp[1][k1];
        }
    }
    for(ll i = 3; i <= a; i++){//>=3
        for(ll j = 1; j <= b; j++){
            for(ll k1 = 1; k1 <= j; k1++){
                ll k2 = j - k1;
                if(k1 > k2) break;//这里有问题!!!!
                dp[i][j] += dp[i - 1][k1];
            }
        }
    }
    cout << dp[a][b] << "\n";
    return 0;
}