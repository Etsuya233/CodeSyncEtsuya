#include <iostream>
#include <queue>
#include <vector>
using namespace std;

typedef struct Ninmu {
    int a, b, c, d, id;
    friend bool operator< (Ninmu aa, Ninmu bb){
        if(aa.a < bb.a) return aa.a < bb.a;
        else if(aa.id < bb.id) return aa.id < bb.id;
        else if(aa.d < bb.d) return aa.d < bb.d;
        else if(aa.c < bb.c) return aa.c < bb.c;
        else return aa.b < bb.b;
    }
} sk;

int n, m;
int v[200005];
priority_queue<sk, vector<sk>, greater<sk>> arr[200005];
int ans[200005];

int main(){
    cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> v[i];
    for(int i = 1; i <= n; i++){
        sk temp;
        temp.id = i;
        cin >> temp.a >> temp.b >> temp.c >> temp.d;
        arr[temp.b].push(temp);
    }
    for(int i = 1; i <= n; i++){
        
    }




}