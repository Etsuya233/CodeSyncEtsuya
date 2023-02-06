#include <iostream>
#include <algorithm>
using namespace std;

int n;
int arr[200010] = {0};
int dp[200010];;
int walked[200010] = {0};
int ans = 0x80000000;

int opera(int i);

int main(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> arr[i];
    }
    for(int i = 1; i <= n; i++){
        ans = max(opera(i), ans);
    }
    cout << ans;
}

int opera(int i){
    if(i == 0) return 0;
    else if(walked[i]) return dp[i];
    else {
        walked[i] = 1;
        return dp[i] = max(dp[i - 1] + arr[i], arr[i]);
    }
}