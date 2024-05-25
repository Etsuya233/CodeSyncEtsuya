#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair<int, int> pii;

int n, d, k;
pii arr[100005];
int cnt[100005] = {0};
int ans[100005] = {0};
priority_queue<pii, vector<pii>, greater<pii>> qu;

int main(){
    cin >> n >> d >> k;
    for(int i = 1; i <= n; i++){
        cin >> arr[i].first >> arr[i].second;
    }
    sort(arr + 1, arr + 1 + n);
    for(int i = 1; i <= n; i++){ // [T, T + D)
        while(!qu.empty() && qu.top().first <= arr[i].first - d){
            cnt[qu.top().second] --;
            qu.pop();
        }
        qu.push(arr[i]);
        cnt[arr[i].second] ++;
        if(cnt[arr[i].second] >= k) ans[arr[i].second] = 1;
    }
    for(int i = 0; i <= 100000; i++){
        if(ans[i]) cout << i << "\n";
    }
    return 0;
}