#include <iostream>
using namespace std;

typedef long long ll;

int main(){
	ll a, b, n;
	cin >> a >> b >> n;
	ll today = 1, left = n;
	while(left > 0){
		ll find = today % 7;
		if(find >= 1 && find <= 5) left -= a;
		else left -= b;
		today++;
	}
	cout << today - 1;
}
