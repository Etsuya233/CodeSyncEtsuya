#include <iostream>
#include <set>
using namespace std;

typedef long long ll;
ll moda = 1000000007;

ll arr[1005];
ll cc[1005][1005] = {0};

ll C(ll a, ll b){
    if(cc[a][b] != 0) return cc[a][b] % moda;
    if(a < b) return 0;
    if(a == b || b == 0) return cc[a][b] = 1;
    return cc[a][b] = (C(a - 1, b - 1) + C(a - 1, b)) % moda;
}

int main(){
    ll m;
    cin >> m;
    while(m--){
        ll n, ji = 0, ou = 0, ans = 0;
        cin >> n;
        for(int i = 1; i <= n; i++){
            cin >> arr[i];
            if(arr[i] % 2 == 1) ji++;
            else ou++;
        }
        if(ji % 2 == 1){
            cout << 0 << "\n";
            continue;
        }
        for(int k = 0; k <= ji; k += 2){
            for(int i = 0; i <= ou; i++){
                ans = (ans + C(ji, k) % moda * C(ou, i) % moda) % moda;
            }
        }
        cout << ans % moda << "\n";
    }
    return 0;
}