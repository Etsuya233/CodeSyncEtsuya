#include <iostream>
#include <cstring>
using namespace std;

int arr[100005] = {0};

int main(){
    int n, k;
    cin >> n >> k;
    for(int i = 1; i <= k; i++){
        int l, r;
        cin >> l >> r;
        arr[l]++;
        arr[r + 1]--;
    }
    for(int i = 1; i <= n; i++){
        arr[i] += arr[i - 1];
    }
    for(int i = 1; i <= n; i++){
        if(arr[i] == 0) cout << "0";
        else if(arr[i] == 1) cout << "1";
        else {
            if(arr[i] % 2 == 0){
                cout << 2 - (arr[i] - 2) / 2;
            } else {
                cout << 0 - (arr[i] - 3) / 2;
            }
        }
        cout << " ";
    }
    cout << "\n";
    return 0;
}