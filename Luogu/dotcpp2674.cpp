#include <iostream>
using namespace std;

typedef long long ll;
int res[20];

ll zerocnt(ll num);

int main(){
    ll n;
    cin >> n;
    ll l = 1, r = 1e18, mid;
    while(l < r){
        while(l < r){
            mid = (l + r) / 2;
            if(zerocnt(mid) < n){
                l = mid + 1;
            } else {
                r = mid;
            }
        }
    } 
    if(zerocnt(l) == n){
        cout << l << "\n";
    } else cout << -1 << "\n";
    return 0;
}

ll zerocnt(ll num){
    /*
    25 2
    x0 x
    5x0 x+1
    !5 1
    */
    ll cnt = 0;
    ll now = 1;
    while(true){
        now *= 5;
        if(now <= num){
            cnt += num / now;
        } else {
            break;
        }
        now *= 2;
        if(now <= num){
            cnt += num / now;
        } else {
            break;
        }
    }
    return cnt;
}