#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
#include <algorithm>
using namespace std;

int n, m;
int visited[100005] = {0};
vector<int> arr[100005];

void dfs(int now);
void bfs();

int main(){
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int x, y;
        cin >> x >> y;
        arr[x].push_back(y);
    }
    for(int i = 1; i <= n; i++){
        sort(arr[i].begin(), arr[i].end());
    }
    dfs(1);
    memset(visited, 0, sizeof(visited));
    cout << "\n";
    bfs();
    
}

void dfs(int now){
    int len = arr[now].size();
    visited[now] = 1;
    cout << now << " ";
    for(int i = 0; i < len; i++){
        if(visited[arr[now][i]] == 0){
            dfs(arr[now][i]);
        }
    }
}

void bfs(){
    queue<int> my;
    my.push(1);
    visited[1] = 1;
    vector<int>::iterator it;
    while(!my.empty()){
        cout << my.front() << " ";
        it = arr[my.front()].begin();
        while(it != arr[my.front()].end()){
            if(visited[*it] == 0){
                my.push(*it);
                visited[*it] = 1;
            }
            it++;
        }
        my.pop();
    }
}