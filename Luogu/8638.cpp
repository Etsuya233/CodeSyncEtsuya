#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int arr[1005] = {0};
int dp[1005][1005] = {0};

int main(){
    char str[1005];
    cin >> str;
    int n = strlen(str);
    for(int i = 1; i <= n; i++){
        arr[i] = str[i - 1] - 'A' + 1;
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(arr[i] == arr[n - j + 1]) dp[i][j] = dp[i - 1][j - 1] + 1;
            else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    cout << n - dp[n][n] << "\n";
    return 0;
}