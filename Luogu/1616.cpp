#include <iostream>
#include <algorithm>
using namespace std;

int dp[10000001] = {0};
int vv[10001];
int tt[10001];
int v, n;

int main(){
    cin >> v >> n;
    for(int i = 1; i <= n; i++) cin >> tt[i] >> vv[i];
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= v; j++){
            dp[j] = max(dp[j], dp[j - tt[i]] + vv[i]);
        }
    }
    cout << dp[v];
}