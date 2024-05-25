#include <iostream>
using namespace std;

int pa[100005];
int n, m;
int dp[100005] = {0};
int sum = 0;
int mx = 0;

int dfs(int x);

int main(){
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        int a;
        cin >> a;
        pa[i] = a;
    }
    while(m--){
        int a;
        cin >> a;
        mx = max(mx, dfs(a));
        cout << sum * 2 - mx << "\n";
    }
    return 0;
}

int dfs(int x){
    if(pa[x] == -1 || dp[x] > 0){
        return dp[x];
    }
    sum++;
    return dp[x] = dfs(pa[x]) + 1;
}