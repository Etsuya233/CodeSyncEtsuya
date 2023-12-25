#include <iostream>
using namespace std;

typedef long long ll;
ll a, b, p;

ll binaryPrime(ll nb);

int main(){
	/*
	y = a^k
	if k % 2 == 0 --> y = a^k/2 * a^k/2
	else          --> y = a^(k-1) * a
	*/
	cin >> a >> b >> p;
	cout << a << "^" << b << " mod " << p << "=" << binaryPrime(b) % p;
	return 0;
}

ll binaryPrime(ll nb){
	if(nb == 0) return 1;
	ll ret;
	if(nb % 2){
		ret = binaryPrime(nb - 1) % p;
		ret = (ret * a) % p;
	} else {
		ret = binaryPrime(nb / 2) % p;
		ret = (ret * ret) % p;
	}
	return ret % p;
}
