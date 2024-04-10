#include <iostream>
using namespace std;

typedef long long ll;
ll n, m, k;
ll ans = 0;
ll moda = 1000000007;
int arr[10][105] = {0};
// int jj[16] = {-2, -2, -2, -1, -1, -1, -1, 0, 0, 1, 1, 1, 1, 2, 2, 2};
// int ii[16] = {-1, 0, 1, -2, -1, 1, 2, -2, 2, -2, -1, 1, 2, -1, 0, 1};
int ii[8] = {-1, 1, -2, 2, -2, 2, -1, 1};
int jj[8] = {-1, 1, -2, 2, -2, 2, -1, 1};

void dfs(int nowi, int nowj, int c);

int main(){
    cin >> n >> m >> k;
    dfs(1, 1, 0);
    cout << ans << "\n";
    return 0;
}

void dfs(int nowi, int nowj, int c){
    if(nowi == n + 1 || c == k){
        if(c == k) ans = (ans + 1) % moda;
        return;
    }
    bool flag = true;
    for(int i = 0; i < 8; i++){
        int iii = nowi + ii[i];
        int jjj = nowj + jj[i];
        if(iii >= 1 && iii <= n && jjj >= 1 && jjj <= m && arr[iii][jjj] == 1){
            flag = false;
            break;
        }
    }
    int nextj = (nowj + 1) % (m + 1);
    int nexti = nowi;
    if(nextj == 0){
        nexti ++;
        nextj = 1;
    }
    if(flag){
        arr[nowi][nowj] = 1;
        dfs(nexti, nextj, c + 1);
        arr[nowi][nowj] = 0;
    }
    dfs(nexti, nextj, c);
}