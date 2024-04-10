#include <iostream>
using namespace std;

typedef long long ll;

int n;
int arr[10002];
ll dp[10002] = {0};
ll moda = 1000000007;

int main(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> arr[i];
    }
    //dp
    dp[0] = 1;
    dp[1] = 1;
    for(int i = 2; i <= n; i++){
        int minn = arr[i], maxn = arr[i];
        for(int j = i; j >= 0; j--){
            minn = min(arr[j], minn);
            maxn = max(arr[j], maxn);
            if(maxn - minn == i - j)
                dp[i] = (dp[j - 1] + dp[i]) % moda;
        }
    }
    //
    cout << dp[n] % moda << "\n";
    return 0;
}