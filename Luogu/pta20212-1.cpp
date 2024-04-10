#include <iostream>
#include <deque>
#include <cstring>
using namespace std;

deque<char> gui[105];
deque<char> ton;
deque<char> line;

int main(){
    int n, m, k;
    cin >> n >> m >> k;
    for(int i = 1; i <= n; i++){
        char arr[1005];
        cin >> arr;
        int len = strlen(arr);
        for(int j = 0; j < len; j++){
            gui[i].push_back(arr[j]);
        }
    }
    while(true){
        int now;
        cin >> now;
        if(now > 0){
            if(!gui[now].empty()){
                if(ton.size() < k){
                    ton.push_back(gui[now].front());
                    gui[now].pop_front();
                } else {
                    line.push_back(ton.back());
                    ton.pop_back();
                    ton.push_back(gui[now].front());
                    gui[now].pop_front();
                }
            }
        } else if(now == 0) {
            if(!ton.empty()){
                line.push_back(ton.back());
                ton.pop_back();
            }
        } else {
            break;
        }
    }
    for(char c: line){
        cout << c;
    }
    return 0;
}