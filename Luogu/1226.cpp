#include <iostream>
using namespace std;

// long long arr[35] = {0};

long long binpow(long long number, long long exp, long long mod);

int main(){
	long long a, b, p;
	cin >> a >> b >> p;
	cout << a << "^" << b << " mod " << p << "=" << binpow(a, b, p);
}

long long binpow(long long number, long long exp, long long mod){
	if(exp == 0) return 1;
	// if(arr[exp] > 0){
		// return arr[exp];
	// } else {
		int res = binpow(number, exp / 2, mod);
		if(exp % 2) return res % mod * res % mod * number % mod;
		else return res % mod * res % mod;
	// }
}