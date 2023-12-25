#include <iostream>
using namespace std;

typedef long long ll;

ll a, b, n;

int main(){
	cin >> a >> b >> n;
	ll cnt = 0, aa = a;
	int i = 0;
	while(aa < b){
		aa *= 10;
		i++;
	}
	for(; i <= n; i++){
		ans = aa / b;
		aa = aa % b;
		aa *= 10;
	}
	cout << ans;
}
