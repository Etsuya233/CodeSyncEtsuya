#include <iostream>
using namespace std;

typedef unsigned long long ull;

int main(){
    ull n;
    cin >> n;
    while(n > 0){
        cout << n << " ";
        n /= 2;
    }
    cout << "\n";
    return 0;
}