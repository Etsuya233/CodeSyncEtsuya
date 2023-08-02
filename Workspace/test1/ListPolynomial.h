#include <cstdio>
#include <vector>
using namespace std;

int k, n, m;
int exist[1002] = {0};
int arrive[1002] = {0};
vector<int> arr[1002];

void dfs(int start, int multiplier);

int main(){
    scanf("%d%d%d", &k, &n, &m);
    for(int i = 0; i < k; i++){
        int temp;
        scanf("%d", &temp);
        exist[temp] = 1;
    }
    for(int i = 0; i < m; i++){
        int x, y;
        scanf("%d%d", &x, &y);
        arr[x].push_back(y);
    }
    for(int i = 1; i <= 1000; i++){
        if(exist[i]) dfs(i, exist[i]);
    }
    int cnt = 0;
    for(int i = 1; i <= 1000; i++){
        if(arrive[i] >= k) cnt++;
    }
    printf("%d", cnt);
}

void dfs(int start, int multiplier){
    arrive[start] += multiplier;
    vector<int>::iterator it = arr[start].begin();
    for(; it != arr[start].begin(); it++){
        dfs(*it, multiplier);
    }
}