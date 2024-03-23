#include <iostream>
using namespace std;

typedef long double lb;

int main(){
    int ans = 0;
    int val = 1000000;
    for(int i = 1; i <= 300; i++){
        int now = 10000 / i + 100 * i;
        if(now < val){
            val = now;
            ans = i;
        }
        cout << i << "\t" << now << "\t" << val << "\n";
    }
    cout << ans << "\n";

}