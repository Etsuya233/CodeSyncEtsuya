#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

typedef pair<int, int> pii;

int n, m;
int t[1005];
vector<pii> arr[1005];
int d[1005] = {0};

void dijkstra();

int main(){
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> t[i];
    }
    for(int i = 1; i <= m; i++){
        int u, v, c;
        cin >> u >> v >> c;
        arr[u].push_back({c + ((u == 1)? 0: t[u]), v});
        arr[v].push_back({c + ((v == 1)? 0: t[v]), u});
    }
    dijkstra();
    cout << d[n] << "\n";
    return 0;
}

void dijkstra(){
    int vis[1005] = {0};
    fill(d, d + 1005, 0x3fffffff);
    priority_queue<pii> qu;
    d[1] = 0;
    qu.push({0, 1});
    while(!qu.empty()){
        pii top = qu.top();
        qu.pop();
        int now = top.second;
        int nowd = top.first;
        if(vis[now] == 1) continue;
        for(pii next: arr[now]){
            int ne = next.second, ned = next.first;
            if(vis[ne] == 0 && nowd + ned < d[ne]){
                d[ne] = nowd + ned;
                qu.push({nowd + ned, ne});
            }
        }
    }
}