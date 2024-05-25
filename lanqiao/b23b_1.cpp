#include <iostream>
#include <cmath>
#include <map>
using namespace std;

typedef long long ll;

int isPrime[5000001] = {0};
ll prime[5000001] = {0};
int vis[5000001] = {0};
map<ll, ll> ma;

void primeFinder();

int main(){
    primeFinder();
    ll ans = 0;
    for(int i = 1; i <= prime[0]; i++){
        // if(i % 1 == 0) cout << i << "\n";
        for(int j = i + 1; j <= prime[0]; j++){
            if(prime[i] * prime[i] >= sqrt(23333333333333L)) break;
            ll now = 1L * prime[i] * prime[i] * prime[j] * prime[j];
            if(now > 23333333333333L) break;
            if(now < 2333L) continue;
            if(now == 20358145139065L){
                cout << prime[i] << " " << prime[j] << "\n";
            }
            ma[now] = 1;
        }
    }
    for(auto a: ma){
        ans++;
    }
    cout << ma.size() << "\n";
    cout << ans << "\n";
    return 0;
}

void primeFinder(){
    for(ll i = 2; i <= 5000000; i++){
        if(vis[i] == 0){
            isPrime[i] = 1;
            prime[++prime[0]] = i;
        }
        for(ll j = 1; j <= prime[0] && i * prime[j] <= 5000000; j++){
            vis[i * prime[j]] = 1;
            if(i % prime[j] == 0) break;
        }
    }
}