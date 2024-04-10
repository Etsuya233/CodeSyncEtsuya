#include <iostream>
using namespace std;

typedef long long ll;

int n, m, kk;
int val[70] = {0};
int getVal(int num);
int dp[102][65][65][21] = {0};
int moda = 1000000007;
int cnt = 0;


int main(){
    cin >> m >> n >> kk;
    cnt = (1 << m);
    //init
    for(int i = 0; i < cnt; i++){
        val[i] = getVal(i);
    }
    //row1
    for(int i = 0; i < cnt; i++){
        dp[1][i][0][val[i]] = 1;
    }
    //row2
    for(int i = 0; i < cnt; i++){
        for(int j = 0; j < cnt; j++){
            if(j & (i << 2)) continue;
            if(j & (i >> 2)) continue;
            for(int k = 0; k + val[i] <= kk; k++){
                dp[2][i][j][k + val[i]] = (dp[2][i][j][k + val[i]] + dp[1][j][0][k]) % moda;
            }
        }
    }
    //other row
    for(int i = 3; i <= n; i++){
        for(int j = 0; j < cnt; j++){
            for(int k1 = 0; k1 < cnt; k1++){
                if(j & (k1 << 2) || j & (k1 >> 2)) continue;
                for(int k2 = 0; k2 < cnt; k2++){
                    if(j & (k2 << 1) || j & (k2 >> 1)) continue;
                    for(int k = 0; k + val[j] <= kk; k++){
                        dp[i][j][k1][k + val[j]] = (dp[i][j][k1][k + val[j]] + dp[i - 1][k1][k2][k]) % moda;
                    }
                }
            }
        }
    }
    //ans
    int ans = 0;
    for(int i = 0; i < cnt; i++){
        for(int j = 0; j < cnt; j++){
            ans = (ans + dp[n][i][j][kk]) % moda;
        }
    }
    cout << ans << "\n";
    return 0;
}

int getVal(int num){
    int ret = 0;
    while(num > 0){
        ret++;
        num -= (num & (-num));
    }
    return ret;
}