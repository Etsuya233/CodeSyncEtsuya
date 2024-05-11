#include <iostream>
#include <vector>
#include <map>
using namespace std;

int n, m;
vector<int> arr[100005];
// int save[105] = {0};
map<int, int> save;

int main(){
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        int cnt;
        cin >> cnt;
        arr[i].push_back(0);
        for(int j = 1; j <= cnt; j++){
            int a;
            cin >> a;
            arr[i].push_back(a);
        }
    }
    int now = 1;
    for(int i = 1; i <= m; i++){
        int op, val;
        cin >> op >> val;
        if(op == 0){
            now = arr[now][val];
        } else if(op == 1){
            save[val] = now;
            cout << now << "\n";
        } else {
            now = save[val];
        }
    }
    cout << now;
    return 0;
}