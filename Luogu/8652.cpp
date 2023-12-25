#include <iostream>
using namespace std;

typedef long long ll;

ll a, b, n;

ll binaryPow(ll a, ll b, ll n);

int main(){
	cin >> a >> b >> n;
	for(int i = n - 1; i <= n + 1; i++){
		cout << a * binaryPow(10, i, b) * 10 / b % 10;
	}
}1

ll binaryPow(ll a, ll b, ll m){
	if(b == 0) return 1;
	if(b % 2){
		return a * binaryPow(a, b - 1, m) % m;
	} else {
		ll mul = binaryPow(a, b / 2, m);
		return mul * mul % m;
	}
}
