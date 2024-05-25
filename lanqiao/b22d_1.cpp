#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int a, b;
char arr[20];
char ans[20];
int len;

void dfs(int d, int aa, int bb);

int main(){
    cin >> arr;
    cin >> a >> b;
    strcpy(ans, arr);
    len = strlen(arr);
    dfs(0, a, b);
    cout << ans << "\n";
    return 0;
}

void dfs(int d, int aa, int bb){
    if(d == len || (aa == 0 && bb == 0)){
        int r = strcmp(arr, ans);
        if(r > 0){
            strcpy(ans, arr);
        }
        return;
    }
    int now = arr[d] - '0';
    if(now + 1 <= bb){
        arr[d] = '9';
        dfs(d + 1, aa, bb - now - 1);
    }
    arr[d] = now + '0';
    int step = min(9 - now, aa);
    if(now + 1 <= bb && now + step < 9) return;
    arr[d] = '0' + now + step;
    dfs(d + 1, aa - step, bb);
    arr[d] = now + '0';
}