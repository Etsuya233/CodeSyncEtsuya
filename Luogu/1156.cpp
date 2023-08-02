#include <iostream>
#include <algorithm>
using namespace std;

typedef struct Trash{
    int t, f, h;
} gomi;

int d, g;
gomi arr[105];
gomi tempa;
int dp[1005];

bool cmpGomi(gomi a, gomi b);

int main(){
    /*
    刷表法：
    dp[高度]=生命值
    吃：
    dp[j] += arr[i].f;
    不吃：
    dp[j + arr[i].h] = dp[j];
    */
    /*
    妈的终于理解了
    dp[i][j]=max(dp[i−1][j]+trash[i].h,dp[i−1][j+trash[i].f])
    
    dp[i][j]=max(dp[i−1][j]+trash[i].c,dp[i−1][j−trash[i].h])
    */
    cin >> d >> g;
    for(int i = 0; i < g; i++){
        cin >> tempa.t >> tempa.f >> tempa.h;
        arr[i] = tempa;
    }
    sort(arr, arr + g, cmpGomi);
    dp[0] = 10;
    for(int i = 0; i < g; i++){
        for(int j = d; j >= 0; j--){
            if(dp[j] >= arr[i].t){
                if(j + arr[i].h >= d){
                    cout << arr[i].t;
                    return 0;
                }
                dp[j + arr[i].h] = max(dp[j], dp[j + arr[i].h]);
                dp[j] += arr[i].f;
            }
        }
    }
    cout << dp[0];
    return 0;
}

bool cmpGomi(gomi a, gomi b){
    return a.t < b.t;
}