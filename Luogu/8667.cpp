#include <iostream>
using namespace std;

typedef long long ll;

int n;
int a[1000000001] = {0}, b[1000000001] = {0}, c[1000000001] = {0};
ll ans = 0;
ll onehaha = 1;

int main(){
	cin >> n;
	for(int i = 0; i < n; i++){
		int d;
		cin >> d;
		a[d] ++;
	}
	for(int i = 0; i < n; i++){
		int d;
		cin >> d;
		b[d] ++;
	}
	for(int i = 0; i < n; i++){
		int d;
		cin >> d;
		c[d] ++;
	}
	//preA
	for(int i = 1; i <= 1000000000; i++) a[i] += a[i - 1];
	//lastC
	for(int i = 1000000000 - 1; i >= 0; i--) c[i] += c[i + 1];
	//operation
	for(int i = 1; i <= 1000000000 - 1; i++) ans += onehaha * a[i - 1] * b[i] * c[i + 1];
	cout << ans;
}
