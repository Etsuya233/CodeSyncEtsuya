#include <iostream>
#include <deque>
using namespace std;

deque<int> stock[10005];
int cnt;
deque<int> qu;
int m;

int main(){
    cin >> m;
    for(int i = 1; i <= m; i++){
        char o;
        int n;
        cin >> o >> n;
        if(n != 0){
            if(o == 'L') qu.push_front(n);
            else qu.push_back(n);
        } else {
            if(o == 'L'){
                while(!qu.empty() && qu.front() != 0){
                    stock[cnt].push_back(qu.front());
                    qu.pop_front();
                }
                if(qu.empty()){
                    qu.push_front(0);
                }
            } else {
                while(!qu.empty() && qu.back() != 0){
                    stock[cnt].push_back(qu.back());
                    qu.pop_back();
                }
                if(qu.empty()){
                    qu.push_back(0);
                }
            }
            cnt++;
        }
    }
    for(int i = 0; i < cnt; i++){
        cout << stock[i].size() << " ";
        for(int & it : stock[i]){
            cout << it << " ";
        }
        cout << "\n";
    }
    return 0;
}