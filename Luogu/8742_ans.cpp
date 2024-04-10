#include <iostream>
#include <cmath>
using namespace std;

int n;
int maxn = 0;
int arr[105];
int dp[2][200005] = {0};

int main(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> arr[i];
        maxn += arr[i];
    }
    maxn += 2;
    //dp
    dp[1][arr[1]] = 1;
    for(int i = 2; i <= n; i++){
        int ii = i % 2;
        int iii = (i - 1) % 2;
        dp[ii][0] = 1;
        dp[iii][0] = 1;
        for(int j = 1; j <= maxn; j++){
            if(dp[iii][j] || dp[iii][abs(arr[i] - j)] || dp[iii][j + arr[i]]){
                dp[ii][j] = 1;
            }
        }
        // for(int j = 1; j <= maxn; j++){
        //     cout << dp[ii][j] << " ";
        // }
        // cout << "\n";
    }
    //output
    int ans = 0;
    for(int i = 1; i <= maxn; i++){
        if(dp[n % 2][i] == 1){
            ans ++;
        }
    }
    cout << ans << "\n";
    return 0;
}