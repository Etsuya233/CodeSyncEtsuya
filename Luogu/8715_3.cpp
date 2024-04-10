#include <iostream>
#include <cstring>
using namespace std;

char arr[100005];
int dp[100005][27] = {0};
int cnt[100005] = {0};
int ans = 0;

int main(){
    cin >> arr + 1;
    arr[0] = '0';
    int n = strlen(arr) - 1;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n - i + 1; j++){
            int now = arr[j + i - 1] - 'a';
            dp[j][now]++;
            if(dp[j][now] == 1) cnt[j]++;
            else if(dp[j][now] == 2) cnt[j]--;
            ans += cnt[j];
        }
    }
    cout << ans << "\n";
    return 0;
}