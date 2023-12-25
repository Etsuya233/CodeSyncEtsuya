#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;
ll arr[100050];
ll n, k;
ll res = 1;
ll moda = 1000000009;

int main(){
	cin >> n >> k;
	for(int i = 0; i < n; i++){
		cin >> arr[i];
	}
	sort(arr, arr + n);
	ll flag = 1;
	int l = 0, r = n - 1;
	if(k % 2){
		res = arr[n - 1];
		r--;
		k--;
		if(arr[n - 1] < 0) flag = -1;
	}
	while(k){
		ll x = arr[l] * arr[l + 1];
		ll y = arr[r] * arr[r - 1];
		if(flag * x <= flag * y){
			res = (res * (y % moda)) % moda;
			r -= 2;
		} else {
			res = (res * (x % moda)) % moda;
			l += 2;
		}
		k -= 2;
	}
	cout << res % moda;
}
