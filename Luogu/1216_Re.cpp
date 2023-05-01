#include <iostream>
#include <algorithm>
using namespace std;

int n;
int dp[1002][1002] = {0};
int arr[1002][1002];
int walked[1002][1002] = {0};

int opera(int i, int j);

int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < i + 1; j++){
            cin >> arr[i][j];
        }
    }
    opera(0, 0);
    cout << dp[0][0];
}

int opera(int i, int j){
    if(i < 0 || j < 0 || j > i || i >= n) return 0;
    walked[i][j] = 1;
    if(walked[i + 1][j] == 0){
        opera(i + 1, j);
    }
    if(walked[i + 1][j + 1] == 0){
        opera(i + 1, j + 1);
    }
    return dp[i][j] = arr[i][j] + ((dp[i + 1][j] > dp[i + 1][j + 1])? dp[i + 1][j]: dp[i + 1][j + 1]);
}