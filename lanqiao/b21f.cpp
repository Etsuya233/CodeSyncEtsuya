#include <iostream>
#include <cmath>
using namespace std;

typedef long long ll;

ll l, r, t;
ll getLoc(ll num);
ll naka(ll l, ll r);
ll inf = 0x3fffffffffffffff;

int main(){
    cin >> t;
    while(t--){
        cin >> l >> r;
        ll lloc = getLoc(l);
        ll rloc = getLoc(r);
        ll lsum = 0, rsum = 0, csum = 0;
        if(lloc == rloc){
            csum = naka(l - naka(1, lloc - 1), r - naka(1, rloc - 1));
        } else {
            for(int i = lloc + 1; i <= rloc - 1; i++){
                csum += naka(1, i);
            }
        }
        if(lloc != rloc){
            lsum = naka(l - naka(1, lloc - 1), lloc);
            rsum = naka(1, r - naka(1, rloc - 1));
        }
        cout << lsum + rsum + csum << "\n";
    }
    return 0;
}

ll naka(ll a, ll b){
    return (a + b) * (b - a + 1) / 2;
}

ll getLoc(ll num){
    ll a = 1, b = 1e10, mid;
    while(a < b){
        mid = (a + b) / 2;
        ll c = naka(1, mid - 1) + 1;
        if(c <= num){
            a = mid + 1;
        } else {
            b = mid;
        }
    }
    return a - 1;
}