#include <iostream>
#include <queue>
using namespace std;

int arr[8] = {0};
int mapa[8][8] = {
    {0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 1, 0, 0, 0, 1, 0},
    {0, 1, 0, 1, 0, 0, 0, 1},
    {0, 0, 1, 0, 1, 0, 0, 1},
    {0, 0, 0, 1, 0, 1, 0, 0},
    {0, 0, 0, 0, 1, 0, 1, 1},
    {0, 1, 0, 0, 0, 1, 0, 1},
    {0, 0, 1, 1, 0, 1, 1, 0},
};

void dfs(int layer);
int judge();
int ans = 0;

int main(){
    dfs(1);
    cout << ans;
}

int judge(){
    int start = 0, sum = 0, cnt = 1;
    for(int i = 1; i <= 7; i++){
        if(arr[i]){
            start = i;
            sum++;
        }
    }
    if(start == 0) return 0;
    queue<int> qu;
    qu.push(start);
    int vis[10] = {0};
    vis[start] = 1;
    while(!qu.empty()){
        int now = qu.front();
        qu.pop();
        for(int i = 1; i <= 7; i++){
            if(arr[i] && mapa[now][i] && vis[i] == 0){
                qu.push(i);
                vis[i] = 1;
                cnt++;
            }
        }
    }
    return cnt == sum;
}

void dfs(int layer){
    if(layer == 8){
        if(judge()) ans++;;
        return;
    }
    arr[layer] = 0;
    dfs(layer + 1);
    arr[layer] = 1;
    dfs(layer + 1);
}