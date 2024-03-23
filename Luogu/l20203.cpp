#include <iostream>
using namespace std;

int main(){
    int arr[200][200] = {0};
    int now = 1;
    for(int i = 2; i <= 50; i++){
        if(i % 2){
            for(int j = i; j >= 1; j--){
                int k = i - j + 1;
                arr[j][k] = ++now;
            }
        } else {
            for(int j = 1; j <= i; j++){
                int k = i - j + 1;
                arr[j][k] = ++now;
            }
        }
    }
    for(int i = 1; i <= 10; i++){
        for(int j = 1; j <= 10; j++){
            cout << arr[i][j] << "\t";
        }
        cout << "\n";
    }
    cout << arr[20][20];
    return 0;
}