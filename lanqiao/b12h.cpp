#include <iostream>
using namespace std;

typedef long long ll;

ll C(ll a, ll b){
    if(a < b) return 0;
    ll ret = 1;
    for(ll i = a, j = 1; j <= b; i--, j++){
        ret = ret * i / j;
    }
    return ret;
}

int main(){
    ll n, k;
    cin >> n >> k;
    ll ans = 0, cnt = 0;
    if(n == 1 && k == 1){
        cout << 1 << "\n";
        return 0;
    }
    for(ll i = 60; i >= 0; i--){
        ll a = 1l << i;
        if((n & a) > 0){
            ans += C(i, k - cnt);
            cnt++;
            if(cnt > k) break;
        }
    }
    cout << ans << "\n";
    return 0;
}