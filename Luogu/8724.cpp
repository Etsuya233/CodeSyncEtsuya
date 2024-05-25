#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

typedef struct MapVertex {
    int n, w, d;
} mv;

int n, m;
vector<mv> arr[30005];
mv tempa;
int dis[30005];

void dijkstra(int start);
void add(int a, int b, int c);

int main(){
    cin >> n >> m;
    for(int i = 1; i <= m; i++){
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        if(d){
            add(a, b + n, c);
            add(b, a + n, c);
            add(a + n, b + n + n, c);
            add(b + n, a + n + n, c);
        } else {
            add(a, b, c);
            add(b, a, c);
            add(a + n, b + n, c);
            add(b + n, a + n, c);
            add(a + n + n, b + n + n, c);
            add(b + n + n, a + n + n, c);
        }
    }
    dijkstra(1);
    int ans = min(dis[n], dis[n + n]);
    ans = min(ans, dis[n + n + n]);
    cout << dis[n] - ans;
    return 0;
}

void add(int a, int b, int c){
    tempa.n = b;
    tempa.w = c;
    arr[a].push_back(tempa);
}

void dijkstra(int start){
    fill(dis, dis + 30005, 0x3fffffff);
    int vis[30005] = {0};
    dis[start] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> qu;
    qu.push(make_pair(0, 1));
    while(!qu.empty()){
        pair<int, int> top = qu.top();
        qu.pop();
        int val = top.first;
        int node = top.second;
        if(vis[node] == 1) continue;
        vis[node] = 1;
        for(mv v: arr[node]){
            if(!vis[v.n] && dis[node] + v.w < dis[v.n]){
                dis[v.n] = dis[node] + v.w;
                qu.push(make_pair(dis[v.n], v.n));
            }
        }
    }
}