#include <iostream>
#include <vector>
using namespace std;

int n;
vector<int> arr[10002];
int ans[10002] = {0};

void dfs(int loc, int val);

int main(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        int loc, pre;
        cin >> loc;
        while(true){
            cin >> pre;
            if(pre == 0) break;
            arr[loc].push_back(pre);
        }
    }
    dfs(n, 0);
    cout << ans[1] + arr[1][0];
}

void dfs(int loc, int val){
    if(val <= ans[loc] && ans[loc] != 0) return;
    ans[loc] = val;
    vector<int>::iterator it = arr[loc].begin();
    int time = *it;
    it++;
    for(; it != arr[loc].end(); it++){
        dfs(*it, val + time);
    }
}