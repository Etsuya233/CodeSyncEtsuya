#include <iostream>
using namespace std;

int main(){
    int arr[25];
    for(int i = 0; i <= 23; i++){
        cin >> arr[i];
    }
    int f = 1;
    while(true){
        int a;
        cin >> a;
        if(a < 0 || a > 23){
            break;
        } else {
            if(f == 1){
                f = 0;
            } else {
                cout << "\n";
            }
            if(arr[a] > 50) cout << arr[a] << " Yes";
            else cout << arr[a] << " No";
        }
    }
    return 0;
}