#include <iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    int l = n;
    while(n >= 3){
        l += n / 3;
        n = n / 3 + n % 3;
    }
    cout << l << "\n";
    return 0;
}