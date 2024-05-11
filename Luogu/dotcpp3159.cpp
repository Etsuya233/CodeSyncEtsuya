#include <iostream>
#include <cstring>
using namespace std;

int main(){
    char arr[1000005];
    cin >> arr;
    int len = strlen(arr);
    int one = 0, zero = 0;
    for(int i = 0; i < len; i++){
        if(arr[i] == '1'){
            one++;
            zero = 0;
            if(one == 2){
                one = 0;
            }   
        } else if(arr[i] == '0'){
            zero++;
            one = 0;
            if(zero == 2){
                zero = 0;
            }  
        } else {
            if(one == 1){
                one = 0;
                arr[i] = '1';
            } else if(zero == 1){
                zero = 0;
                arr[i] = '0';
            } else {
                if(i != len - 1){
                    if(arr[i + 1] == '1'){
                        one++;
                        if(one == 2){
                            one = 0;
                        }
                        arr[i] = '1';
                    } else if(arr[i + 1] == '0'){
                        zero++;
                        if(zero == 2) zero = 0;
                        arr[i] = '0';
                    } else {
                        one++;
                        if(one == 2) one = 0;
                        arr[i] = '1';
                    }
                } else {
                    one++;
                    if(one == 2) one = 0;
                    arr[i] = '1';
                }
            }
        }
    }
    int ans = 0;
    for(int i = 1; i < len; ){
        if(arr[i] == arr[i - 1]){
            ans++;
            i += 2;
        } else i++;
    }
    cout << ans << "\n";
    return 0;
}