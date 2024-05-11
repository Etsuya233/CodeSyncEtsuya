#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;
ll dp[2040];
ll inf = 0x3fffffffffffffff;

int main(){
    ll n;
    fill(dp, dp + 2040, inf);
    dp[0] = 0;
    dp[1] = 1;
    for(ll i = 2; i <= 2021; i++){
        for(ll j = 0; j < i; j++){
            dp[i] = min(dp[i], 1l + 2l * dp[j] + 3l * dp[i - j - 1] + 1l * j * j * (i - j - 1));
        }
        cout << i << "\t\t" << dp[i] << "\n";//666
    }
    cout << dp[2021];
}