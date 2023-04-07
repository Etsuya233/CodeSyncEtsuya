#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main(){
    string in, out;
    cin >> in >> out;
    out.reserve();
    long long amount = 0, ans = 0;
    for(int i = 1; i < in.length(); i++){
        if(in[i] == out[i] && in[i - 1] == out[i - 1]) amount++;
    }
    ans = pow(2, amount);
    cout << ans;
}