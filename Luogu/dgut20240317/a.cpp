#include <iostream>
using namespace std;

int main(){
    int a;
    cin >> a;
    if(a >= 1200){
        cout << "tuiyile\n";
    }else {
        cout <<  1200 - a << "\n";
    }
    return 0;
}