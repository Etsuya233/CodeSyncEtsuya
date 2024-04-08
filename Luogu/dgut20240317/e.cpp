#include <iostream>
using namespace std;

typedef long long ll;

ll moda = 1000000007;

ll f(ll a, ll b);

int arr[1005][1005] = {0};

int main(){
    int a, b;
    cin >> a >> b;
    cout << f(a, b) << "\n";
    return 0;
}

ll f(ll a, ll b){
    if(arr[a][b] != 0) return arr[a][b];
    if(a == 0) return b % moda;
    if(b == 0) return a % moda;
    return arr[a][b] = (f(a - 1, b) + f(a, b - 1)) % moda;
}