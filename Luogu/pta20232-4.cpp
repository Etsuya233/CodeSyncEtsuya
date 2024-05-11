#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> arr;
vector<vector<int>> vis;
int cnt = 0, cnt1 = 0;
int ii[4] = {0, 1, 0, -1};
int jj[4] = {1, 0, -1, 0};
int n, m;

int dfs(int nowi, int nowj, int c);

int main(){
    cin >> n >> m;
    arr = vector(n + 2, vector<int>(m + 2));
    vis = vector(n + 2, vector<int>(m + 2));
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            char num;
            cin >> num;
            arr[i][j] = num - '0';
        }
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(arr[i][j] != 0 && vis[i][j] == 0){
                int a = dfs(i, j, cnt + 1);
                if(a) cnt1++;
                cnt++;
            }
        }
    }
    cout << cnt << " " << cnt1;
    return 0;
}

int dfs(int nowi, int nowj, int c){
    int ret = arr[nowi][nowj] - 1;
    for(int i = 0; i < 4; i++){
        int nexti = nowi + ii[i];
        int nextj = nowj + jj[i];
        if(nexti >= 1 && nexti <= n && nextj >= 1 && nextj <= m && arr[nexti][nextj] != 0 && vis[nexti][nextj] == 0){
            vis[nexti][nextj] = 1;
            ret += dfs(nexti, nextj, c);
        }
    }
    return ret;
}