#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;

ll d1(ll layer);
ll d2(ll layer);
ll d3(ll layer);
ll d4(ll layer);

int main(){
    ll x, y;
    cin >> x >> y;
    if(x == 0 && y == 0){
        cout << 0 << "\n";
        return 0;
    }
    if(x == -1 && y == 0){
        cout << 1 << "\n";
        return 0;
    }
    if(x == -1 && y == 1){
        cout << 2 << "\n";
        return 0;
    }
    ll res = 0;
    //2 1 4 3
    ll l2 = 0, l1 = 0, l4 = 0, l3 = 0;
    ll n;
    if(x < 0 && y >= 0){
        n = max(-x, y);
        l2 = l1 = l4 = l3 = n - 1;
    } else if(x >= 0 && y > 0){
        n = max(x, y);
        l2 = n;
        l1 = l4 = l3 = n - 1;
    } else if(y <= 0 && x > 0){
        n = max(x, -y);
        l2 = l1 = n;
        l4 = l3 = n - 1;
    } else {
        n = max(-(x + 1), -y);
        l2 = l1 = l4 = n;
        l3 = n - 1;
    }
    res += d1(l1) + d2(l2) + d3(l3) + d4(l4);
    if(x < 0 && y >= 0){
        res += y;
        if(y == n){
            res += n + x;
        }
    } else if(x >= 0 && y > 0){
        res += x;
        if(x == n){
            res += n - y;
        }
    } else if(y <= 0 && x > 0){
        res += -y;
        if(-y == n){
            res += n - x;
        }
    } else {
        res += -x;
        if(-x - 1 == n){
            res += n + y;
        }
    }
    cout << res << "\n";
    return 0;
}

ll d1(ll layer){
    ll res = (layer + 1) * layer;
    return res;
}

ll d4(ll layer){
    ll res = (layer + 1) * layer;
    return res;
}

ll d3(ll layer){
    ll res = ((2 * layer + 1) + 3) * layer / 2;
    return res;
}

ll d2(ll layer){
    ll res = (layer + 1) * layer;
    return res + 1;
}