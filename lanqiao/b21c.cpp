#include <iostream>
using namespace std;

int md[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int mdr[13] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int isRun(int year){
    return year % 4 == 0 && (year % 100 != 0 || year % 400 == 0);
}

int main(){
    int y = 2001, m = 1, d = 1;
    int cnt = 0;
    while(y != 2022 || m != 1 || d != 1){
        int yy = y, mm = m, dd = d, sum = 0;
        while(yy > 0){
            sum += yy % 10;
            yy /= 10;
        }
        while(mm > 0){
            sum += mm % 10;
            mm /= 10;
        }
        while(dd > 0){
            sum += dd % 10;
            dd /= 10;
        }
        for(int a = 0; a * a <= sum; a++){
            if(a * a == sum){
                cnt++;
                cout << y << "-" << m << "-" << d << ":" << a * a << "\n";
                break;
            }
        }
        if(isRun(y) == 1){
            d++;
            if(d > mdr[m]){
                d = 1;
                m++;
            }
            if(m > 12){
                m = 1;
                y++;
            }
        } else{
            d++;
            if(d > md[m]){
                d = 1;
                m++;
            }
            if(m > 12){
                m = 1;
                y++;
            }
        }
    }
    cout << cnt << "\n";
}

