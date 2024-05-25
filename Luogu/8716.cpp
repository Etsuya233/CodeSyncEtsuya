#include <iostream>
using namespace std;

int m1[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int m2[13] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}; //run

int ans = 0;
char da[20];
int jj1 = 0;
int jj2 = 0;

int judge(int y);
int judge2();
int judge3();

int main(){
    cin >> da;
    int y = (da[0] - '0') * 1000 + (da[1] - '0') * 100 + (da[2] - '0') * 10 + (da[3] - '0') * 1;
    int m = (da[4] - '0') * 10 + (da[5] - '0') * 1;
    int d = (da[6] - '0') * 10 + (da[7] - '0') * 1, s = 6;
    while(true){
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
        da[7] = d % 10 + '0';
        da[6] = d / 10 % 10 + '0';
        if(m > 12){
            m = 1;
            y++;
        }
        da[5] = m % 10 + '0';
        da[4] = m / 10 % 10 + '0';
        da[3] = y % 10 + '0';
        da[2] = y / 10 % 10 + '0';
        da[1] = y / 100 % 10 + '0';
        da[0] = y / 1000 % 10 + '0';
        s++;
        if(s > 7) s = 1;
        if(!jj1){
            if(judge2()) jj1 = 1;
        }
        if(!jj2){
            if(judge3()) jj2 = 1;
        }
        if(jj1 && jj2){
            break;
        }
    }
    // cout << ans <<int judge2() "\n";
}

int judge(int y){
    if((y % 4 == 0 && y % 100 != 0) || y % 400 == 0) return 1;
    return 0;
}

int judge2(){
    if(da[0] == da[7] && da[1] == da[6] && da[2] == da[5] && da[3] == da[4]){
        cout << da << "\n";
        return 1;
    }
    return 0;
}

int judge3(){
    if(da[0] == da[2] && da[0] == da[5] && da[0] == da[7] && da[1] == da[3] && da[1] == da[4] && da[1] == da[6]){
        cout << da << "\n";
        return 1;
    }
    return 0;
}