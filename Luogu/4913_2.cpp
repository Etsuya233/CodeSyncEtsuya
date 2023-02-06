#include <cstdio>

typedef struct Node{
    int l, r;
} node;

int ans = 1;
node arr[1000001];

int main(){
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        scanf("%d%d", &arr[i].l, &arr[i].r);
    }
    printf("%d", ans);
}

void dfs(int root, int depth){
    if(root == 0){
        ans = (depth > ans)? depth: ans;
        return;
    } else {
        dfs(arr[root].l, depth + 1);
        dfs(arr[root].r, depth + 1);
    }
}