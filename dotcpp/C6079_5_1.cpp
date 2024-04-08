#include <iostream>
#include <cstring>
using namespace std;

typedef long long ll;

ll hashm = 999997, base = 1e9 + 1; //TODO hashm讲究?
ll hasht[1000000];
ll hashcnt[1000000] = {0};
ll hasha[1000000] = {0};
int vis[1000000] = {0};
ll n, m;
ll ans = 0;

ll hashfind(ll val);
ll hashrize(ll x, ll y);
bool judge(ll x1, ll y1, ll x2, ll y2, ll r);
void dfs(ll x, ll y, ll r);

int main(){
    cin >> n >> m;
    memset(hasht, -1, sizeof(hasht));
    for(int i = 1; i <= n; i++){
        ll x, y, r;
        cin >> x >> y >> r;
        ll key = hashrize(x, y);
        ll loc = hashfind(key);
        hasht[loc] = key;
        hashcnt[loc]++;
        hasha[loc] = max(r, hasha[loc]);
    }
    for(int i = 1; i <= m; i++){
        ll x, y, r;
        cin >> x >> y >> r;
        dfs(x, y, r);
    }
    cout << ans << "\n";
    return 0;
}

ll hashrize(ll x, ll y){
    return base * x + y;
}

ll hashfind(ll val){
    ll a = (val % hashm + hashm) % hashm;
    while(hasht[a] != -1 && hasht[a] != val){
        a++;
        if(a == hashm) a = 0;
    }
    return a;
}

bool judge(ll x1, ll y1, ll x2, ll y2, ll r){
    ll dist = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
    return dist <= r * r;
}

void dfs(ll x, ll y, ll r){
    for(ll i = -r; i <= r; i++){
        for(ll j = -r; j <= r; j++){
            ll key = hashrize(x + i, y + j);
            ll loc = hashfind(key);
            if(!hashcnt[loc] || vis[loc]) continue;
            if(judge(x, y, x + i, y + j, r)){
                ans += hashcnt[loc];
                vis[loc] = 1;
                dfs(x + i, y + j, hasha[loc]);
            }
        }
    }
}