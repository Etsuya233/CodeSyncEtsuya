#include <iostream>
#include <cmath>
#include <ctime>
using namespace std;

int n;
int arr[105];
int dp[100005][2] = {0};
int maxw = 0;

int main(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> arr[i];
        maxw += arr[i];
    }
    maxw ++;
    for(int i = 1; i <= n; i++){
        dp[arr[i]][i % 2] = 1;
        // cout << i << ":\n";
        auto ts = clock();
        for(int j = 0; j <= maxw; j++){
            if(dp[j][(i + 1) % 2] == 1){
                // cout << "\t" << arr[i] + j << "  " << abs(arr[i] - j) << "\n";
                dp[j][i % 2] = 1;
                dp[arr[i] + j][i % 2] = 1;
                dp[abs(arr[i] - j)][i % 2] = 1;
            }
        }
        auto te = clock();
        cout << (te - ts) << "\n";
    }
    int ans = 0;
    for(int i = 1; i <= maxw; i++){
        if(dp[i][n % 2] == 1) ans++;
    }
    cout << ans << "\n";
    return 0;
}