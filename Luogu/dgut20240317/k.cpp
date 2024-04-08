#include <iostream>
#include <cmath>
using namespace std;

int main(){
    int n;
    int l, r;
    cin >> n;
    cin >> l >> r;
    int ans = 0;
    for(int i = 1; i <= n; i++){
        int now;
        cin >> now;
        ans += now / r;
        if(now % r >= l) ans++;
    }
    if(ans % 2) cout << "First\n";
    else cout << "Second\n";
    return 0;
}