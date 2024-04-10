#include <iostream>
using namespace std;

int n, m;
int arr[105][15] = {0};
int sta[250], cnt = 1, val[250] = {0};
int h[105] = {0};
int dp[105][250][250] = {0};

int getVal(int num);

int main(){
    cin >> n >> m;
    //input and hill
    for(int i = 1; i <= n; i++){
        char str[15];
        cin >> str;
        for(int j = 0; j < m; j++){
            arr[i][j + 1] = (str[j] == 'H');
            h[i] = (h[i] << 1) + arr[i][j + 1]; //1 represent hill
        }
    }
    //each status
    sta[1] = 0;
    for(int i = 1; i <= (1 << m) - 1; i++){
        if(i & (i << 2)) continue;
        if(i & (i << 1)) continue;
        if(i & (i >> 1)) continue;
        if(i & (i >> 2)) continue;
        cnt++;
        sta[cnt] = i;
        val[cnt] = getVal(i);
    }
    //row 1
    for(int i = 1; i <= cnt; i++){
        if((sta[i] & h[1]) == 0) dp[1][i][1] = val[i];
    }
    //row 2
    for(int i = 1; i <= cnt; i++){
        if(sta[i] & h[2]) continue;
        for(int j = 1; j <= cnt; j++){
            if(sta[j] & h[1] || sta[j] & sta[i]) continue;
            dp[2][i][j] = dp[1][j][1] + val[i];
        }
    }
    //other rows
    for(int i = 3; i <= n; i++){
        for(int j = 1; j <= cnt; j++){
            if(sta[j] & h[i]) continue;
            for(int k1 = 1; k1 <= cnt; k1++){
                if(sta[k1] & h[i - 1] || sta[k1] & sta[j]) continue;
                for(int k2 = 1; k2 <= cnt; k2++){
                    if(sta[k2] & h[i - 2] || sta[k2] & sta[j] || sta[k2] & sta[k1]) continue;
                    dp[i][j][k1] = max(dp[i][j][k1], dp[i - 1][k1][k2] + val[j]);
                }
            }
        }
    }
    //ans
    int ans = 0;
    for(int i = 1; i <= cnt; i++){
        for(int j = 1; j <= cnt; j++){
            ans = max(ans, dp[n][i][j]);
        }
    }
    cout << ans << "\n";
    return 0;
}

int getVal(int num){
    int ret = 0;
    while(num > 0){
        ret ++;
        num -= (num & (-num));
    }
    return ret;
}