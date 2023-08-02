#include <iostream>
#include <cstring>
using namespace std;

int si, sj, di, dj;
int n, m, t;
int arr[105][105];
int dp[105][105][16] = {0};

int ans = 0;

int ii[4] = {-1, 0, 1, 0};
int jj[4] = {0, -1, 0, 1};

int dfs(int nowi, int nowj, int time);

int main(){
    std::ios::sync_with_stdio(false);
    memset(dp, -1, sizeof(dp));
    cin >> n >> m >> t;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            char a;
            cin >> a;
            if(a == '.') arr[i][j] = 1;
            else arr[i][j] = 0;
        }
    }
    cin >> si >> sj >> di >> dj;
    si--;
    sj--;
    di--;
    dj--;
    if(!arr[si][sj]){
        cout << 0;
        return 0;
    }
    cout << dfs(si, sj, 0);
}

int dfs(int nowi, int nowj, int time){
    if(dp[nowi][nowj][time] != -1) return dp[nowi][nowj][time];
    int route = 0;
    if(time > t) return 0;
    if(nowi == di && nowj == dj && time == t){
        return 1;
    }
    for(int i = 0; i < 4; i++){
        int nexti = nowi + ii[i], nextj = nowj + jj[i];
        if(nexti >= 0 && nexti < n && nextj >= 0 && nextj < m && arr[nexti][nextj] && (abs(di - nowi) + abs(dj - nowj) <= (t - time))){
            route += dfs(nexti, nextj, time + 1);
            
        }
    }
    return dp[nowi][nowj][time] = route;
}