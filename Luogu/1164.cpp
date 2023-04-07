#include <cstdio>
//DFS最后一个点TLE

int n, m, sum = 0, price[1002] = {0};

void dfs(int loc, int money);

int main(){
    scanf("%d%d", &n, &m);
    for(int i = 0; i < n; i++){
        scanf("%d", &price[i]);
    }
    dfs(0, 0);
    printf("%d", sum);
    return 0;
}

void dfs(int loc, int money){
    if(money > m || loc > n){
        return;
    }
    if(money == m){
        sum++;
        return;
    };
    dfs(loc + 1, money + price[loc]);
    dfs(loc + 1, money);
}