#include <iostream>
using namespace std;

int n;

int main(){
    cin >> n;
    if(n == 1) {
        cout << "1" << "\n";
        return 0;
    } else {
        int ans = n * 2;
        //l
        for(int i = 0; i < n / 2; i++){
            cout << (ans -= 2) << "\n";
        }
        if(n % 2){
            cout << ans - 2 << "\n";
        }
        ans -= 2;
        for(int i = 0; i < n / 2; i++){
            cout << (ans += 2) << "\n";
        }
    }
    return 0;

}