#include <cstdio>
#include <cstring>
using namespace std;

int n, m;
int res[100005] = {0};
int need[100005] = {0};
int diff[100005] = {0};
int d[100005] = {0};
int s[100005] = {0};
int t[100005] = {0};

int feasibility(int n);

int main(){
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i++){
        scanf("%d", &res[i]);
    }
    for(int i = 0; i < m; i++){
        scanf("%d%d%d", &d[i], &s[i], &t[i]);
    }
    if(feasibility(m)){
        printf("0");
        return 0;
    }
    int l = 1, r = m, half;
    while(l < r){
        half = (l + r) /2;
        if(feasibility(half)){
            l = half + 1;
        } else {
            r = half;
        }
    }
    printf("-1\n%d", l);
}

int feasibility(int n){
    memset(diff, 0, sizeof(diff));
    need[1] = res[1];
    for(int i = 1; i <= n; i++){
        diff[s[i]] += d[i];
        diff[t[i] + 1] -= d[i];
    }
    for(int i = 1; i <= n; i++){
        need[i] = need[i - 1] + diff[i];
        if(need[i] > res[i]) return 0;
    }
    return 1;
}