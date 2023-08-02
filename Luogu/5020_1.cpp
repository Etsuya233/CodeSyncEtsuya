#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

/*
害 还是太弱了 知道是背包问题 但是递推式还写错
看了题解是完全背包的装满背包问题就懂了凑
昨天还调了一天错误的程序。。。。
*/

int dp[25005];
int arr[105];
int t;

int main(){
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int res = n;
        for(int i = 0; i < n; i++){
            cin >> arr[i];
        }
        memset(dp, 0, sizeof(dp));
        dp[0] = 1;
        sort(arr, arr + n);
        int maximum = arr[n - 1];
        for(int i = 0; i < n; i++){
            if(dp[arr[i]]){
                res--;
                continue;
            }
            for(int j = arr[i]; j <= maximum; j++){
                dp[j] = dp[j] || dp[j - arr[i]];
            }
        }
        cout << res << endl;
    }
}