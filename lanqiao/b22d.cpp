#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

char arr[20];
int a, b;

int main(){
    cin >> arr >> a >> b;
    int len = strlen(arr);
    for(int i = 0; i < len; i++){
        int now = arr[i] - '0';
        if(now == 9) continue;
        if(now + 1 <= b){
            arr[i] = '9';
            b -= now + 1;
        } else {
            int step = min(a, 9 - now);
            arr[i] = '0' + now + step;
            a -= step;
        }
    }
    cout << arr << "\n";
    return 0;
}