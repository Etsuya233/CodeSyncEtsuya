#include <iostream>
#include <cmath>
using namespace std;

typedef long long ll;

int isPrime[10000001] = {0};
int prime[10000001] = {0};
int vis[10000001] = {0};

void primeFinder();

int main(){
    primeFinder();
    ll ans = 0;
    for(ll i = 2023; i <= 23333333333333L; i++){
        ll ii = sqrt(i);
        if(ii * ii != i) continue;
        if(i % 100000 == 0) cout << i << "\n";
        for(ll j = 1; prime[j] <= ii / 2 && j <= prime[0]; j++){
            ll le = ii / prime[j];
            if(le * prime[j] != ii) continue;
            if(isPrime[le] && le != prime[j]){
                ans++;
                break;
            }
        }
    }
    cout << ans << "\n";
    return 0;
}

void primeFinder(){
    for(int i = 2; i <= 10000000; i++){
        if(vis[i] == 0){
            isPrime[i] = 1;
            prime[++prime[0]] = i;
        }
        for(int j = 1; j <= prime[0] && i * prime[j] <= 10000000; j++){
            vis[i * prime[j]] = 1;
            if(i % prime[j] == 0) break;
        }
    }
}