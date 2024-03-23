#include <iostream>
#include <cmath>
using namespace std;

//ans 11027421

typedef long double ld;
typedef long long ll;

ll len = 23333333LL;
ld res = 11625907.5798l;

int main(){
	ld val = 0x7fffffff;
	ll ans = 0;
	for(ll i = 1; i <= len / 2; i++){
		ld ret = - (1.0l * i / len * i * (logl(i) - logl(len)) / logl(2)) - 1.0l * (len - i) / len * (len - i) * (logl(len - i) - logl(len)) / logl(2);
		if(abs(res - ret) <= 1e-4){
			cout << i << "\n";
		}
	}
	cout << val << "\t" << ans;
}
