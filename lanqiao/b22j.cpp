#include <iostream>
#include <algorithm>
#include <utility>
using namespace std;

typedef pair<int, int> pii;

int n;
pii arr[1005];
int dp[20005] = {0};
int m;
int ans = 0;

bool cmpNode(pii a, pii b);

int main(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> arr[i].first >> arr[i].second;
        m += arr[i].first;
    }
    sort(arr + 1, arr + 1 + n, cmpNode);
    for(int i = 1; i <= n; i++){
        int w = arr[i].first, v = arr[i].second;
        for(int j = m; j >= w; j--){
            if(j - w <= v){
                dp[j] = max(dp[j], dp[j - w] + v);
            }
        }
    }
    for(int i = 0; i <= m; i++){
        ans = max(ans, dp[i]);
    }
    cout << ans << "\n";
    return 0;
}

bool cmpNode(pii a, pii b){
    if(a.first + a.second != b.first + b.second){
        return a.first + a.second < b.first + b.second;
    } else if(a.first < b.first) return a.first != b.first;
    else return a.second != b.second;
}