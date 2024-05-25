#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
int dp[100005][18] = {0};
int deg[100005] = {0};
vector<int> arr[100005];
int depth[100005] = {0};
int dis[100005] = {0};

void dfs(int now, int de, int di);
int lca(int a, int b);

int main(){
    cin >> n >> m;
    for(int i = 1; i < n; i++){
        int a, b;
        cin >> a >> b;
        if(a > b) swap(a, b);
        deg[a]++;
        deg[b]++;
        arr[a].push_back(b);
        dp[b][0] = a;
    }
    for(int i = 1; i <= 17; i++){
        for(int j = 1; j <= n; j++){
            dp[j][i] = dp[dp[j][i - 1]][i - 1];
        }
    }
    dfs(1, 0, deg[1]);
    for(int i = 1; i <= m; i++){
        int a, b;
        cin >> a >> b;
        if(a == b){
            cout << deg[a] << "\n";
            continue;
        }
        int c = lca(a, b);
        cout << dis[a] + dis[b] - 2 * dis[c] + deg[c] << "\n";
    }
    return 0;
}

void dfs(int now, int de, int di){
    depth[now] = de;
    dis[now] = di;
    for(int c: arr[now]){
        dfs(c, de + 1, di + deg[c]);
    }
}

int lca(int a, int b){
    if(depth[a] > depth[b]) swap(a, b);
    for(int i = 17; i >= 0; i--){
        if(depth[a] <= depth[dp[b][i]]){
            b = dp[b][i];
        }
        if(a == b) return a;
    }
    for(int i = 17; i >= 0; i--){
        if(dp[a][i] != dp[b][i]){
            a = dp[a][i];
            b = dp[b][i];
        }
    }
    return (dp[a][0]) == 0? 1: dp[a][0];
}