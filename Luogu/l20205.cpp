#include <iostream>
using namespace std;

int m1[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int m2[13] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}; //run

int judge(int y);
int ans = 0;

int main(){
    int y = 2000, m = 1, d = 1, s = 6;
    while(y != 2020 || m != 10 || d != 2){
        if(s == 1 || d == 1) ans += 2;
        else ans += 1;
        d++;
        if(!judge(y)){ 
            if(d > m1[m]){
                d = 1;
                m++;
            }
        } else { //run
            if(d > m2[m]){
                d = 1;
                m++;
            }
        }
        if(m > 12){
            m = 1;
            y++;
        }
        s++;
        if(s > 7) s = 1;
    }
    cout << ans << "\n";
}

int judge(int y){
    if((y % 4 == 0 && y % 100 != 0) || y % 400 == 0) return 1;
    return 0;
}