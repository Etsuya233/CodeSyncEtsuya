#include <iostream>
using namespace std;

typedef long long ll;

ll n;
ll dp[3][10000005] = {0};
ll moda = 1000000007;

int main(){
    cin >> n;
    dp[2][1] = 1;
    // dp[0][0] = 1;
    // dp[1][0] = 1;
    dp[2][0] = 1;
    for(int i = 2; i <= n; i++){
        dp[0][i] = (dp[2][i - 2] + dp[1][i - 1]) % moda;
        dp[1][i] = (dp[2][i - 2] + dp[0][i - 1]) % moda;
        dp[2][i] = (((dp[2][i - 1] + dp[2][i - 2]) % moda + dp[1][i - 1]) % moda + dp[0][i - 1]) % moda;
    }
    cout << dp[2][n] % moda << "\n";
    return 0;
}