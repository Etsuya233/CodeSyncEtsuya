#include <cstdio>

int dp[100001][100001] = {0};

int main(){
    int n;
    int num[100001], num1[100001];
    scanf("%d", &n);
    for(int j = 1; j <= n; j++){
        scanf("%d", num[j]);
    }
    for(int i = 1; i <= n; i++){
        scanf("%d", num1[i]);
    }
    for(int i = 1; i <= n; i++){
        for(int j = 0; j <= n; j++){
            if(num[i] == num[j]) dp[i][j] = dp[i - 1][j - 1] + 1;
            else dp[i][j] = (dp[i][j - 1] > dp[i - 1][j])? dp[i][j - 1]: dp[i - 1][j];
        }
    }
    printf("%d", dp[n][n]);
}