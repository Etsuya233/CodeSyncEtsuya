#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

typedef long long ll;

typedef struct Nodea{
    ll loc, val;
    friend bool operator< (struct Nodea a, struct Nodea b){
        if(a.val != b.val) return a.val < b.val;
        else return a.loc < b.loc;
    }
} node;

node arr[500005];
int vis[500005] = {0};
priority_queue<node> qu;
priority_queue<node> qu1;
ll n;
ll ans = 0;
int getHalf(int val);

int main(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> arr[i].val;
        arr[i].loc = i;
        qu.push(arr[i]);
    }
    sort(arr + 1, arr + 1 + n);
    for(int i = 1; i <= n; i++){
        qu1.push(arr[i]);
        if(arr[i].val > arr[n - 1].val / 2) break;
    }
    while(!qu.empty()){
        ll a = -1, b = -1;
        while(vis[qu.top().loc] != 0) qu.pop();
        if(!qu.empty()){
            a = qu.top().val;
            qu.pop();
        }
        while(vis[qu.top().loc] != 0) qu.pop();
        if(!qu.empty()){
            b = qu.top().val;
            qu.pop();
        }
        if(a == -1 && b == -1){
            break;
        } else if(a == -1 || b == -1){
            ans += max(a, b);
        } else {
            ans += a + b;
            // while(qu1.top().val > min(a, b) / 2) qu1.pop();
            // if(!qu1.empty()){
            //     vis[qu1.top().loc] = 1;
            //     qu1.pop();
            // }
            int loc = getHalf(min(a, b) / 2);
            loc--;
            for(; loc > 0; loc--){
                if(vis[arr[loc].loc] == 0){
                    vis[arr[loc].loc] = 1;
                    break;
                }
            }
        }
    }
    cout << ans << "\n";
    return 0;
}

int getHalf(int val){
    ll l = 1, r = n, mid;
    while(l < r){
        mid = (l + r) / 2;
        if(arr[mid].val <= val){
            l = mid + 1;
        } else r = mid;
    }
    return l;
}