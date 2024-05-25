#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;

ll a[50000] = {0}, b[50000] = {0}, c[50000] = {0}; // 0 2 3

int main(){
    int nowpos = 1;
    for(int i = 1; i <= 2023; i++){
        int digit = 0;
        int t = i;
        while(t > 0){
            t /= 10;
            digit ++;
        }
        t = i;
        int cnt = 1;
        while(t > 0){
            int n = t % 10;
            if(n == 0){
                a[++a[0]] = nowpos + digit - cnt;
            } else if(n == 2){
                b[++b[0]] = nowpos + digit - cnt;
            } else if(n == 3){
                c[++c[0]] = nowpos + digit - cnt;
            }
            t /= 10;
            cnt++;
        }
        nowpos += digit;
    }
    sort(a + 1, a + 1 + a[0]);
    sort(b + 1, b + 1 + b[0]);
    sort(c + 1, c + 1 + c[0]);
    ll ans = 0;
    for(int i = 1; i <= b[0]; i++){ //2
        int j = upper_bound(a + 1, a + 1 + a[0], b[i]) - a; //0
        for( ; j <= a[0]; j++){
            int k = upper_bound(b + 1, b + 1 + b[0], a[j]) - b; //2
            for(; k <= b[0]; k++){
                int q = upper_bound(c + 1, c + 1 + c[0], b[k]) - c;
                ans += c[0] - q + 1;
            }
        }
    }
    cout << ans << "\n";
    return 0;
}