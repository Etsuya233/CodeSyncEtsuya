#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<int> arr[10002];
int ans[10002] = {0};

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

    int ansans = 0;
    vector<int>::iterator it;
    for(int i = 1; i <= n; i++){
        int maximum = 0;
        it = arr[i].begin();
        int time = *it;
        it++;
        for(; it != arr[i].end(); it++){
            if(ans[*it] > maximum) maximum = ans[*it];
        }
        ans[i] = maximum + time;
        ansans = max(ans[i], ansans);
    }

    // 返回所有任务都被完成的最短时间
    cout << ansans;
}