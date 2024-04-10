#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;

typedef struct Nodea{
    ll loc = 0, val = 0;
    friend bool operator< (struct Nodea a, struct Nodea b){
        if(a.val != b.val) return a.val < b.val;
        else return a.loc < b.loc;
    }
} node;

node arr[500005];
int vis[500005] = {0};
ll n;
ll ans = 0;

int main(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> arr[i].val;
        arr[i].loc = i;
    }
    sort(arr + 1, arr + 1 + n);
    int ph = 1, pt1 = n, pt2 = n - 1;
    for(int i = 1; i <= n; i++){
        if(arr[i].val > arr[n - 1].val / 2){
            ph = i;
            break;
        }
    }
    while(true){
        int a, b;
        while(vis[arr[pt1].loc] != 0 && pt1 >= 1) pt1--;
        vis[a = arr[pt1].loc] = 1;
        while(vis[arr[pt2].loc] != 0 && pt2 >= 1) pt2--;
        vis[b = arr[pt2].loc] = 1;
        if(a == 0 && b == 0){
            break;
        } else if(a == 0 || b == 0){
            ans += max(arr[pt1].val, arr[pt2].val);
        } else {
            ans += arr[pt1].val + arr[pt2].val;
            while((vis[arr[ph].loc] != 0 || arr[ph].val > (min(arr[pt1].val, arr[pt2].val) / 2)) && ph >= 1) ph--;
            if(ph >= 1) vis[arr[ph].loc] = 1;
        }
    }
    cout << ans << "\n";
    return 0;
}
