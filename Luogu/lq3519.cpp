#include <iostream>
#include <cstring>
using namespace std;

char arr[1000005];

int main(){
    int ans = 0;
    cin >> arr;
    int len = strlen(arr);
    if(len == 1){
        cout << "0" << "\n";
        return 0;
    }
    int c0 = 0, c1 = 0;
    if(arr[0] == '?' && len > 1 && arr[1] != '?'){
        arr[0] = arr[1];
    } else if(arr[0] == '?' && len > 1 && arr[1] == '?'){
        arr[0] = '0';
    }
    if(arr[0] == '0') c0 = 1;
    else c1 = 1;
    for(int i = 1; i < len - 1; i++){
        if(arr[i] == '?'){
            char l = arr[i - 1], r = arr[i + 1];
            if(l == '0' && c0 == 1){
                arr[i] = '0';  
            } else if(l == '1' && c1 == 1){
                arr[i] = '1';
            } else if(r == '0'){
                arr[i] = '0';
            } else if(r == '1'){
                arr[i] = '1';
            } else {
                arr[i] = '0';
            }
        }
        if(arr[i] == '0'){
            c0 = (c0 + 1) % 2;
            if(c0 == 0) ans++;
            c1 = 0;
        } else {
            c0 = 0;
            c1 = (c1 + 1) % 2;
            if(c1 == 0) ans++;
        }
    }
    if(arr[len - 1] == '?' && (c1 == 1 || c0 == 1)){
        ans++;
    } else if(arr[len - 1] == '0' && c0 == 1) ans++;
    else if(arr[len - 1] == '1' && c1 == 1) ans++;
    cout << ans << "\n";
    return 0; 
}