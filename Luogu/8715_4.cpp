#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

char arr[100005];
vector<int> dp[26];
int ans = 0;

int main(){
    cin >> arr;
    int n = strlen(arr);
    for(int i = 0; i < n; i++){
        dp[arr[i] - 'a'].push_back(i);
    }
    for(int i = 0; i < 26; i++){
        int size = dp[i].size();
        for(int j = 0; j < size; j++){
            int l = (j == 0)? 0: dp[i][j - 1] + 1;
            int r = (j == size - 1)? n - 1: dp[i][j + 1] - 1;
            int now = dp[i][j];
            ans += (now - l + 1) * (r - now + 1);
        }
    }
    cout << ans << "\n";
    return 0;
}