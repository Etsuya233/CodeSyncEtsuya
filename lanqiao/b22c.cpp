#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;

ll n, m;
ll arr[200005] = {0};
ll b[200005] = {0};

bool judge(ll a);

int main(){
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> arr[i];
    }
    for(int i = 1; i <= n; i++){
        cin >> b[i];
    }
    ll l = 0, r = 40000000005, mid;
    while(l < r){
        mid = (l + r) / 2;
        if(judge(mid)){
            l = mid + 1;
        } else {
            r = mid;
        }
    }
    cout << l - 1 << "\n";
    return 0;
}

bool judge(ll a){
    ll nowm = m;
    for(int i = 1; i <= n; i++){
        ll need = a - arr[i];
        if(need > nowm || need > b[i]) return false;
        if(need > 0){
            nowm -= need;
        }
        if(nowm < 0) return false;
    }
    return true;
}