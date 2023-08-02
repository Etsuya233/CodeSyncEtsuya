#include <iostream>
using namespace std;

int n, m;
int arr[1005][1005];
int vis[1005][1005];
int flag = 0;
int ii[] = {-1, 0, 0, 1};
int jj[] = {0, 1, -1, 0};

void dfs(int nowi, int nowj, int mid);

int main(){
    int l = 0, r = 0;
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> arr[i][j];
            r = max(arr[i][j], r);
        }
    }
    //Binary
    while(l < r){
        flag = 0;
        int mid = (l + r) / 2;
        dfs(1, 1, mid);
        if(flag) r = mid;
        else l = mid + 1;
    }
    cout << l;
}

void dfs(int nowi, int nowj, int mid){
    if(nowi == n){
        flag = 1;
        return;
    }
    for(int i = 0; i < 4; i++){
        int nexti = nowi + ii[i];
        int nextj = nowj + jj[i];
        if(nexti == 0 || nexti > n || nextj == 0 || nextj > m || vis[nexti][nextj] || arr[nexti][nextj] > mid) continue;
        vis[nexti][nextj] = 1;
        dfs(nexti, nextj, mid);
        if(flag) return;
    }
}