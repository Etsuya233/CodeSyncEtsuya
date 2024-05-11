#include <iostream>
using namespace std;

int main(){
    long long dp[2025][11]={0};   // dp[i][j]表示选j个数总和为i的方案数
    dp[0][0]=1;
    int i,j,k;
    for (i=1;i<=2022;i++){
        for (j=10;j>=1;j--){
            for (k=i;k<=2022;k++){
                dp[k][j]+=dp[k-i][j-1];
                cout << dp[k][j] << "\n";
            }
        }
    }
	printf("%lld\n",dp[2022][10]);
}