#include <iostream>
using namespace std;

int main(){
    int n, m, k;
    cin >> n >> m >> k;
    int p1 = 1, p2 = 2, p3 = 3;
    int arr[1010] = {0, n, m};
    while(true){
        int ans = arr[p1] * arr[p2];
        if(ans >= 10){
            arr[p3 + 1] = ans % 10;
            ans /= 10;
            arr[p3] = ans;
            p3 += 2;
        } else {
            arr[p3] = ans;
            p3 ++;
        }
        if(p3 > k) break;
        p1++;
        p2++;
    }
    for(int i = 1; i <= k - 1; i++){
        cout << arr[i] << " ";
    }
    cout << arr[k];
    return 0;
}