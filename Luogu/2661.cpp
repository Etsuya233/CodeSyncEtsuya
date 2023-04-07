#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int n;
int walked[200002];
int tp[200002];
int minimum = 0x7fffffff;

void dfs(int start, int round);

int main(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> tp[i];
    }
    for(int i = 1; i <= n; i++){
        memset(walked, 0, sizeof(walked));
        dfs(i, 1);
    }
    cout << minimum;
}

void dfs(int start, int round){
    if(walked[start]){
        minimum = min(round - 1, minimum);
        return;
    }
    walked[start] = 1;
    dfs(tp[start], round + 1);
}