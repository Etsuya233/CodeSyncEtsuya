#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

typedef long double lb;
typedef struct Node {
    int id;
    lb p;
} node;

int n, m, k;
lb rea[45];
lb arr[45][25];
vector<int> jiken;
node p[45];
int pro[25] = {0};
lb sum = 0;

bool cmpNode(node a, node b);

int main(){
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> rea[i];
        rea[i] *= 0.01L;
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> arr[i][j];
            arr[i][j] *= 0.01L;
        }
    }
    cin >> k;
    for(int i = 1; i <= k; i++){
        int a;
        cin >> a;
        pro[a] = 1;
    }
    for(int i = 1; i <= n; i++){
        lb nowp = 1.0L;
        for(int j = 1; j <= m; j++){
            if(pro[j]) nowp *= arr[i][j];
            else nowp *= (1.0L - arr[i][j]);
        }
        nowp *= rea[i];
        p[i].id = i;
        p[i].p = nowp;
        sum += nowp;
    }
    for(int i = 1; i <= n; i++){
        p[i].p = p[i].p / sum;
    }
    sort(p + 1, p + 1 + n, cmpNode);
    for(int i = 1; i <= n; i++){
        p[i].p *= 100.0L;
        printf("%d %.2Lf\n", p[i].id, p[i].p);
    }
    return 0;
}

bool cmpNode(node a, node b){
    if(a.p != b.p) return a.p > b.p;
    else return a.id < b.id;
}