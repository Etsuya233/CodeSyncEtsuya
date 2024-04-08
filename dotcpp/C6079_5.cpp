#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

typedef struct Point{
    int x, y, r;
} po;

typedef long long ll;

int n, m;

po arr[500004];
int vis[500004];
int ans = 0;

bool cmpX(po a, po b);
double dist(po a, po b);
void dfs(int x, int y, int r);
int binary(int num);
bool judge(int x1, int y1, int x2, int y2, int r);

int main(){
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> arr[i].x >> arr[i].y >> arr[i].r;
    }
    sort(arr + 1, arr + 1 + n, cmpX);
    for(int i = 1; i <= m; i++){
        int x, y, r;
        cin >> x >> y >> r;
        dfs(x, y, r);
    }
    cout << ans << "\n";
    return 0;
}

void dfs(int x, int y, int r){
    int bl = binary(x - r), br = binary(x + r + 1);
    for(int i = bl; i <= br; i++){
        if(!vis[i] && judge(x, y, arr[i].x, arr[i].y, r)){
            ans ++;
            vis[i] = 1;
            dfs(arr[i].x, arr[i].y, arr[i].r);
        }
    }
}

bool cmpX(po a, po b){
    return a.x <= b.x;
}

int binary(int num){
    int l = 1, r = n, mid;
    while(l < r){
        int mid = (l + r) / 2;
        if(arr[mid].x < num){
            l = mid + 1;
        } else {
            r = mid;
        }
    }
    return l;
}

bool judge(int x1, int y1, int x2, int y2, int r){
    return (1LL * x1 - x2) * (1LL * x1 - x2) + (1LL * y1 - y2) * (1LL * y1 - y2) <= 1LL * r * r;
}