#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef struct Component {
    int loc, p, e = 1;
} com;

int n, m, d, r;
vector<com> arr;
int dis[202][202];
int path[202][202] = {0};
vector<int> city[202];
int nd = 1, nc = 1, np = 10;

int main(){
    cin >> n >> m >> r >> d;
    for(int i = 0; i < n; i++){
        com temp;
        cin >> temp.loc >> temp.p;
        arr.push_back(temp);
        city[temp.loc].push_back(i);
    }
    fill(dis, dis + 202 * 202, 0x3fffffff);
    for(int i = 1; i <= r; i++){
        int a, b, c;
        cin >> a >> b >> c;
        dis[a][b] = c;
        dis[b][a] = c;
    }
    //floyd
    for(int k = 0; k < m; k++){
        for(int i = 0; i < m; i++){
            for(int j = 0; j < m; j++){
                if(i == j || i == k || j == k) continue;
                if(dis[i][k] + dis[k][j] < dis[i][j]){
                    dis[i][j] = dis[i][k] + dis[k][j];
                    path[i][j] = path[i][k] + path[k][j];
                }
                if(dis[i][k] + dis[k][j] == dis[i][j]){
                    path[i][j] = min(path[i][k] + path[k][j], path[i][j]);
                }
            }
        }
    }
    //solve
    while(true){
        int nc = find_com();
        if(dis[nc][arr[nc].loc] < d - nd){ //假设还有时间去下一个对手的城市
            beat();
        } else {

        }
    }

}

int find_com(){
    //并列情况下优先选最近的；距离也并列的情况下选途径城市最少的；再有并列就选城市编号最小的。
    int ci = -1, cc = -1, cp = 0x3fffffff, cd = 0x3fffffff;
    for(int i = 0; i < arr.size(); i++){
        if(arr[i].e == 1 && arr[i].p - np > 0){
            if(arr[i].p - np < cp - np)           {
                ci = i;
                cc = arr[i].loc;
                cp = arr[i].p;
                cd = dis[nc][cc];
            } else if(arr[i].p - np == cp - np){
                if(path[nc][cc] > path[nc][arr[i].loc]){
                    ci = i;
                    cc = arr[i].loc;
                    cp = arr[i].p;
                    cd = dis[nc][cc];
                } else if(path[nc][cc] == path[nc][arr[i].loc]){
                    if()
                }
            }
        } 
    }
}

void beat(){

}