#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
#include <queue>
using namespace std;

typedef struct MapNode {
    int n, w;
} node;

int n, m, q;
int de = 100001;
vector<node> arr[200010];
unordered_set<int> se[200010];
node tempa;

int main(){
    cin >> n >> m >> q;
    for(int i = 1; i <= m; i++){
        int u, v, c, d;
        cin >> u >> v >> c >> d;
        if(se[u].find(v) == se[u].end()){
            tempa.n = v;
            tempa.w = c;
            arr[u].push_back(tempa);
            tempa.n = v + de;
            tempa.w = d;
            arr[u].push_back(tempa);
            se[u].insert(v);
        } else {
            int j = 0;
            for(; j < arr[u].size() && arr[u][j].n != v; j++);
            arr[u][j].w = min(arr[u][j].w, c);
            arr[u][j + 1].w = min(arr[i][j + 1].w, d);
        }
    }
    



}