#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
using namespace std;

int n, m, k;
int mm[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
vector<int> arr[400];
int dp[400][5005] = {0};

int main(){
    for(int i = 1; i <= 12; i++) mm[i] += mm[i - 1];
    cin >> n >> m >> k;
    for(int i = 1; i <= n; i++){
        int a, b, c;
        cin >> a >> b >> c;
        int date = mm[a - 1] + b;
        arr[date].push_back(c);
    }
    dp[0][0] = 1;
    for(int i = 1; i <= 365; i++){
        for(int j = 0; j <= m; j++){
            dp[i][j] = dp[i - 1][j];
            for(int v: arr[i]){
                dp[i][j] = dp[i][j] || v == j;
                if(i - k >= 0){
                    if(j - v >= 0) dp[i][j] = dp[i][j] || dp[i - k][j - v];
                }
            }
        }
    }
    for(int i = m; i >= 0; i--){
        if(dp[365][i] == 1){
            cout << i << "\n";
            break;
        }
    }
    return 0;
}

/*
dp[i][j] = 
    dp[i - 1][j] || dp[i - k][j - v[q]] 
*/