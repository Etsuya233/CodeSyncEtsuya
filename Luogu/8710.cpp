#include <iostream>
#include <vector>
using namespace std;

int n, m;
int pa[10005] = {0};
vector<int> arr[10005];
int ans[10005] = {0};
void uniu(int a, int b);

int main(){
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        pa[i] = i;
        arr[i].push_back(i);
    }
    for(int i = 1; i <= m; i++){
        int a, b, c;
        cin >> a >> b >> c;
        if(a == 1){
            uniu(b, c);
        } else {
            int f = pa[b];
            for(int node: arr[f]){
                ans[node] += c;
            }
        }
    }
    for(int i = 1; i <= n; i++){
        cout << ans[i] << " ";
    }
    cout << "\n";
    return 0;
}

void uniu(int a, int b){
    int fa = pa[a], fb = pa[b];
    if(fa == fb) return;
    //如果不是同一个集合
    pa[fb] = fa;
    for(int node: arr[fb]){
        pa[node] = fa;
        arr[fa].push_back(node);
    }
    arr[fb].clear();
}