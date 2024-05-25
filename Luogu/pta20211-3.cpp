#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int main(){
    char str[10];
    cin >> str;
    int len = strlen(str);
    if(len == 6){
        for(int i = 0; i < 4; i++){
            cout << str[i];
        }
        cout << "-";
        for(int i = 4; i <= 5; i++){
            cout << str[i];
        }
    } else {
        int y = (str[0] - '0') * 10 + str[1] - '0';
        int m = (str[2] - '0') * 10 + str[3] - '0';
        if(y < 22){
            printf("20%02d-%02d", y, m);
        } else {
            printf("19%02d-%02d", y, m);
        }
    }
    return 0;
}