#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

typedef struct Opera {
    int type, val, t; //type 0 某任务结束 1 某任务开始
    friend bool operator< (Opera a, Opera b){
        if(a.t != b.t) return a.t < b.t;
        else if(a.type != b.type) return a.type < b.type;
        else return a.val < b.val;
    };
    friend bool operator> (Opera a, Opera b){
        if(a.t != b.t) return a.t > b.t;
        else if(a.type != b.type) return a.type > b.type;
        else return a.val > b.val;
    };
} ope;

typedef struct Ninmu {
    int a, b, c, d; //t machine t2 cost
} sk;

int n, m;
int v[200005];
sk arr[200005];
priority_queue<ope, vector<ope>, greater<ope>> qu;

int main(){
    cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> v[i];
    for(int i = 1; i <= m; i++){
        cin >> arr[i].a >> arr[i].b >> arr[i].c >> arr[i].d;
        ope temp;
        temp.type = 1;
        temp.t = arr[i].a;
        temp.val = i;
        qu.push(temp);
    }
    while(!qu.empty()){
        ope now = qu.top();
        qu.pop();
        sk task = arr[now.val];
        if(now.type == 1){
            if(v[task.b] >= task.d){
                v[task.b] -= task.d;
                cout << v[task.b] << "\n";
                ope temp;
                temp.type = 0;
                temp.t = task.a + task.c;
                temp.val = now.val;
                qu.push(temp);
            } else {
                cout << "-1\n";
            }
        } else {
            v[task.b] += task.d;
        }
    }
    return 0;
}