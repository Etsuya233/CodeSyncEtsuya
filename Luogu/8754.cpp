#include <iostream>
#include <cmath>
using namespace std;

typedef long long ll;

ll prime[1000000] = {0};
int vis[1000002] = {0};
void primeinit();

int main(){
    ll n;
    cin >> n;
    primeinit();
    ll a = n;
    ll num[200] = {0};
    ll fre[200] = {0};
    ll cnt = 0;
    ll sqr = (ll)sqrt(1.0 * n);
    if(n == 1){
        cout << "1\n";
        return 0;
    }
    for(int i = 1; i <= prime[0] && prime[i] <= sqr; i++){
        if(a % prime[i] == 0){
            cnt++;
            num[cnt] = prime[i] ;
            while(a > 0 && a % prime[i] == 0){
                a /= prime[i];
                fre[cnt]++;
            }
        }
        if(a == 1) break;
    }
    if(a != 1){
        cnt++;
        num[cnt] = a;
        fre[cnt] = 1;
    }
    ll ans = 1;
    for(int i = 1; i <= cnt; i++){
        if(fre[i] % 2) ans *= num[i];
    }
    cout << ans << "\n";
    return 0;
}

void primeinit(){
    for(ll i = 2; i <= 1000000; i++){
        if(vis[i] == 0){
            prime[++prime[0]] = i;
        }
        for(int j = 1; j <= prime[0] && i * prime[j] <= 1000000; j++){
            vis[i * prime[j]] = 1;
            if(i % prime[j] == 0) break;
        }
    }
}