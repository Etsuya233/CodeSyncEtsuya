#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int n;
int arr[10000] = {0};
int dp[10000] = {0, 1};
int ans = 1;

void opera(int loc);

int main(){
    memset(dp, 1, sizeof(dp));
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> arr[i];
    opera(n);
    cout << ans;

}

void opera(int loc){
    for(int i = 1; i <= loc; i++){
        if(arr[i] < arr[loc]){
            dp[loc] = max(dp[i] + 1, dp[loc]);
            ans = max(dp[loc], ans);
        }
    }
}