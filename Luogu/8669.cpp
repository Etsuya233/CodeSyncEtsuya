#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;
ll f = 1;
ll arr[100005];
ll moda = 1000000009;

int main(){
	ll n, k;
	cin >> n >> k;
	for(int i = 1; i <= n; i++){
		cin >> arr[i];
	}
	sort(arr + 1, arr + 1 + n);
	ll cnt = 0;
	ll ans = 1;
	ll p1 = 1, p2 = n;
	if(k % 2 == 1){
		ans = arr[n];
		if(arr[n] < 0) f = -1;
		cnt = 1;
		p2 --;
	}
	while(cnt < k){
		if(arr[p2] * arr[p2 - 1] * f <= arr[p1] * arr[p1 + 1] * f){
			ll a = arr[p1] * arr[p1 + 1] % moda; 
			ans = ans * a % moda;
			p1 += 2;
		} else {
			ll a = arr[p2] * arr[p2 - 1] % moda; 
			ans = ans * a % moda;
			p2 -= 2;
		}
		cnt += 2;
	}
	cout << ans % moda << "\n";
	return 0;
}
