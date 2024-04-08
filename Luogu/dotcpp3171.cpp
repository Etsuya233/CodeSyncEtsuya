#include <iostream>
using namespace std;

typedef long long ll;
ll moda = 1000000007;
int c[1010][1010] = {{1}, {1, 1}};

ll C(ll a, ll b);

int main(){
    ll t;
    cin >> t;
    while(t--){
        ll n, a = 0, b = 0;
        cin >> n;
        for(int i = 1; i <= n; i++){
            ll now;
            cin >> now;
            if(now % 2 == 0) b++;
            else a++;
        }
        ll ans = 1, ansa = 0;
        if(a % 2 == 1){
            ans = 0;
        } else {
            for(int i = 1; i <= b; i++){
                ans *= 2;
                ans %= moda;
            }
            for(int i = 0; i <= a; i+=2){
                ansa += C(a, i);
                ansa %= moda;
            }
            if(ansa != 0) ans = (ans * ansa) % moda;
        }
        cout << ans << "\n";
    }
    return 0;
}

ll C(ll a, ll b){
    if(c[a][b] != 0) return c[a][b];
    else if(a == b || b == 0) return c[a][b] = 1;
    else return c[a][b] = (C(a - 1, b - 1) + C(a - 1, b)) % moda;
}