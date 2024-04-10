#include <iostream>
using namespace std;

typedef long long ll;

ll zerocnt(ll num);

int main(){
    ll k;
    cin >> k;
    ll l = 1, r = 0x7fffffffffffffff, mid;
    while(l < r){
        mid = l + (r - l) / 2;
        if(zerocnt(mid) < k){
            l = mid + 1;
        } else r = mid;
    }
    if(zerocnt(l) == k){
        cout << l << "\n";
    } else cout << -1 << "\n";
    return 0;
}

ll zerocnt(ll num){
    ll ret = 0;
    while(num > 0){
        ret += (num /= 5);
    }
    return ret;
}