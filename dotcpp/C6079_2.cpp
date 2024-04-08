#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

typedef long long ll;

ll n;
ll ma, mb;
ll a[100005];
ll b[100005];

int main(){
    cin >> n;
    cin >> ma;
    for(int i = ma; i > 0; i--){
        cin >> a[i];
    }
    cin >> mb;
    for(int i = mb; i > 0; i--){
        cin >> b[i];
    }
    ll ans = 0;
    ll realDigit = 1;
    for(int i = 1; i <= max(ma, mb); i++){
        ll plus = (a[i] - b[i]) * realDigit % 1000000007;
        ans = (ans + plus) % 1000000007;
        ll digit = 2;
        digit = max(2LL, max(a[i], b[i]) + 1);
        realDigit = (digit * realDigit) % 1000000007;
    }
    cout << ans % 1000000007 << "\n";
    return 0;
}