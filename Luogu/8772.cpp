#include <iostream>
using namespace std;

typedef long long ll;

ll arr[200005];
ll pre[200005] = {0};

int main(){
    ll n;
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> arr[i];
        pre[i] += pre[i - 1] + arr[i];
    }
    ll ans = 0;
    for(int i = 1; i <= n; i++){
        ans += arr[i] * (pre[n] - pre[i]);
    }
    cout << ans << "\n";
    return 0;
}