#include <iostream>
#include <cstring>
using namespace std;

int main(){
    int n;
    cin >> n;
    int arr[100005];
    int vis[100005] = {0};
    for(int i = 1; i <= n; i++){
        cin >> arr[i];
    }
    int now = 1;
    bool ok = false;
    while(vis[now] == 0){
        vis[now] = 1;
        if(now == n){
            ok = true;
            break;
        }
        now = arr[now];
    }
    cout << (ok? "YES\n": "NO\n");
    return 0;
}