#include <iostream>
using namespace std;

int main(){
    long long a, b, n;
    cin >> a >> b >> n;
    long long days = 0;
    days = n / (5 * a + 2 * b);
    n -= days * (5 * a + 2 * b);
    days *= 7;
    for(int i = 1; i <= 7; i++){
        if(i <= 5){
            n -= a;
            days ++;
        } else {
            n -= b;
            days ++;
        }
        if(n <= 0){
            break;
        }
    }
    cout << days;
    return 0;
}



