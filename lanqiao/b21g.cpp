#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

typedef long long ll;

int main(){
    ll n, t, rt = 1;
    char arr[2][10005];
    char ori[10005];
    cin >> n >> t >> arr[0];
    while(rt < n){
        rt *= 2;
    }
    t = (t % rt == 0)? rt: (t % rt);
    strcpy(ori, arr[0]);
    for(int i = 1; i <= t; i++){
        arr[i % 2][0] = arr[(i + 1) % 2][0];
        for(int j = 1; j < n; j++){
            if(arr[(i + 1) % 2][j] != arr[(i + 1) % 2][j - 1]){
                arr[i % 2][j] = '1';
            } else {
                arr[i % 2][j] = '0';
            }
        }
    }
    cout << arr[t % 2] << "\n";
    return 0;
}