#include <iostream>
using namespace std;

int gcd(int a, int b);

int main(){
    int ans = 0;
    for(int i = 1; i <= 2020; i++){
        for(int j = i + 1; j <= 2020; j++){
            if(gcd(i, j) == 1) ans += 2;
        }
    }
    cout << ans + 1 << "\n";
}

int gcd(int a, int b){
    if(b == 0) return a;
    return gcd(b, a % b);
}