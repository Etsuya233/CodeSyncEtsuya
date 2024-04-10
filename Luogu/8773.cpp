#include <iostream>
#include <cmath>
using namespace std;

typedef long long ll;

typedef struct HashNode{
    ll target = -1, loc = 0;
} hn;

ll n, m, x;
ll arr[100005];
hn has[200003];
ll ans[100005];
ll st[100005][17] = {0};

ll hsf(ll target);
void hsp(ll target, ll pos);
void initst();
ll query(ll l, ll r);

int main(){
    cin >> n >> m >> x;
    for(int i = 1; i <= n; i++){
        cin >> arr[i];
        ll t = x ^ arr[i];
        ans[i] = hsf(t);
        st[i][0] = ans[i];
        hsp(arr[i], i);
    }
    initst();
    for(int i = 1; i <= m; i++){
        ll l, r;
        cin >> l >> r;
        ll a = query(l, r);
        if(a >= l && a < r) cout << "yes\n";
        else cout << "no\n";
    }
    return 0;
}


ll hsf(ll target){
    ll loc = target % 200003;
    while(true){
        if(has[loc].target == -1 || has[loc].target == target){
            break;
        }
        loc = (loc + 1) % 200003;
    }
    return has[loc].loc;
}

void hsp(ll target, ll pos){
    ll loc = target % 200003;
    while(true){
        if(has[loc].target == -1 || has[loc].target == target){
            break;
        }
        loc = (loc + 1) % 200003;
    }
    has[loc].target = target;
    has[loc].loc = pos;
}

void initst(){
    for(int j = 1; j <= 16; j++){
        for(int i = 1; i + (1 << j) - 1 <= n; i++){
            st[i][j] = max(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
        }
    }
}

ll query(ll l, ll r){
    ll k = log2(r - l + 1);
    ll x = r - (1 << k) + 1;
    return max(st[l][k], st[x][k]);
}