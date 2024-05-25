#include <iostream>
#include <cmath>
using namespace std;

int main(){
    int a, b;
    cin >> a >> b;
    int sum = 1;
    for(int i = 2; i <= a + b; i++) sum *= i;
    cout << sum << "\n";
    return 0;
}