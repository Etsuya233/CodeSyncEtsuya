#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

typedef long long ll;

ll st[100005][17] = {0};
ll n = 100000;
void initst();
ll query(ll l, ll r);

int main(){
    for(int i = 1; i <= n; i++){
        st[i][0] = i;
    }
    initst();
    ll l, r;
    cin >> l >> r;
    cout << query(l, r);
    return 0;
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