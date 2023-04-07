#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, m;
vector<int> arr[100005];
int visited[100005] = {0};

void dfs(int loc, int val);

int main(){
    cin >> n >> m;
    for(int i = 1; i <= m; i++){
        int x, y;
        cin >> x >> y;
        arr[y].push_back(x);
    }
    for(int i = n; i > 0; i--){
        dfs(i, i);
    }
    for(int i = 1; i <= n; i++){
        if(visited[i]) cout << visited[i] << " ";
        else cout << i << " ";
    }
}

void dfs(int loc, int val){
    if(visited[loc]) return;
    visited[loc] = val;
    vector<int>::iterator it = arr[loc].begin();
    for(; it != arr[loc].end(); it++){
        dfs(*it, val);
    }
}