#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int n;
int f[505][505];
int cnt[505] = {0};
int gen[505];
int dis[505] = {0};
int ans[2] = {0x3fffffff, 0x3fffffff};

int main(){
    scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        fill(f[i], f[i] + n + 1, 0x3fffffff);
        f[i][i] = 0;
    }
    for(int i = 1; i <= n; i++){
        char gender[5];
        scanf("%s", gender);
        gen[i] = (gender[0] == 'M')? 1: 0;
        int a;
        scanf("%d", &a);
        cnt[i] = a;
        for(int j = 1; j <= a; j++){
            int b, c;
            scanf("%d:%d", &b, &c);
            f[i][b] = c;
        }
    }
    //floyd
    for(int k = 1; k <= n; k++){
        for(int j = 1; j <= n; j++){
            for(int i = 1; i <= n; i++){
                f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
            }
        }
    }
    //dis
    for(int j = 1; j <= n; j++){
        for(int i = 1; i <= n; i++){
            if(gen[i] != gen[j]){
                dis[j] = max(dis[j], f[i][j]); //异性与j的最大距离
            }
        }
        ans[gen[j]] = min(ans[gen[j]], dis[j]);
    }
    //ans
    int bl = 0;
    for(int i = 1; i <= n; i++){
        if(gen[i] == 0 && dis[i] == ans[0]){
            if(bl == 1) printf(" ");
            printf("%d", i);
            bl = 1;
        } 
    }
    printf("\n");
    bl = 0;
    for(int i = 1; i <= n; i++){
        if(gen[i] == 1 && dis[i] == ans[1]){
            if(bl == 1) printf(" ");
            printf("%d", i);
            bl = 1;
        } 
    }
    printf("\n");
    return 0;
}