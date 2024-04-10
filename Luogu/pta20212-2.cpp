#include <iostream>
#include <vector>
using namespace std;

int n;
vector<int> arr[10005];
int vis[10005] = {0};
int len = 0;
int ans[10005], temp[10005];

void dfs(int now, int layer);

int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        int a;
        cin >> a;
        for(int j = 1; j <= a; j++){
            int b;
            cin >> b;
            arr[i].push_back(b);
        }
    }
    for(int i = 0; i < n; i++){
        if(vis[i] == 0) dfs(i, 1);
    }
    cout << len << "\n";
    for(int i = 1; i < len; i++){
        cout << ans[i] << " ";
    }
    cout << ans[len];
    return 0;
}

void dfs(int now, int layer){
    temp[layer] = now;
    vis[now] = 1;
    if(arr[now].empty()){
        if(layer > len){
            for(int i = 1; i <= layer; i++){
                ans[i] = temp[i];
            }
            len = layer;
        } else if(layer == len){
            bool s = true;
            for(int i = 1; i <= layer; i++){
                if(temp[i] != ans[i]){
                    s = temp[i] < ans[i];
                    break;
                }
            }
            if(s){
                for(int i = 1; i <= layer; i++){
                    ans[i] = temp[i];
                }
            }
        }
        return;
    }
    for(int c: arr[now]){
        dfs(c, layer + 1);
    }
}