#include <iostream>
using namespace std;

int m, s, t;

int main(){
    cin >> m >> s >> t;
    int s1 = 0, s2 = 0; //s1 跑步， s2 闪现
    for(int i = 0; i < t; i++){
        s1 += 17;
        if(m >= 10){
            s2 += 60;
            m -= 10;
        } else {
            m += 4;
        }
        if(s2 > s1) s1 = s2;
        if(s1 >= s){
            cout << "Yes\n" << i + 1;
            return 0;
        }
    }
    cout << "No\n" << s1;

}