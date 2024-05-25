#include <iostream>
using namespace std;

typedef long long ll;
ll a[100005] = {0}, b[100005] = {0, 1, 1};
ll n;

int main(){
    cin >> n;
    if(n == 1){
        cout << "1\n";
        return 0;
    }
    for(ll i = 3; i <= 44723; i++){
        ll m = i / 2;
        if(i % 2 == 1){
            for(int j = 1; j <= m; j++){
                a[j] = b[j - 1] + b[j];
                if(a[j] == n){
                    cout << (i * (i - 1)) / 2 + j << "\n";
                    return 0;
                }
            }
            a[m + 1] = b[m] * 2;
            if(a[m + 1] == n){
                cout << (i * (i - 1)) / 2 + m + 1 << "\n";
                return 0;
            }
        } else {
            for(int j = 1; j <= m; j++){
                b[j] = a[j - 1] + a[j];
                if(b[j] == n){
                    cout << (i * (i - 1)) / 2 + j << "\n";
                    return 0;
                }
            }
        }
    }
    cout << (n * (n + 1)) / 2 + 2 << "\n";
    return 0;
}