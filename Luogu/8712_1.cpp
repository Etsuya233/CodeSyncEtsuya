#include <iostream>
#include <cmath>
using namespace std;

typedef long long ll;
typedef long double lb;

ll n, k, ans = 0;
ll arr[100050], ha[11][100050];

int main(){
	cin >> n >> k;
	for(int i = 1; i <= n; i++){
		cin >> arr[i];
		ll t = arr[i] % k;
		for(int j = 0; j <= 10; j++){
			ha[j][t % k] ++;
			t *= 10;
		}
	}
	for(int i = 1; i <= n; i++){
		//digit
		ll len = 0, a = arr[i];
		while(a > 0){
			a /= 10;
			len ++;
		}
		//calc
		ll f = (k - arr[i] % k) % k;
		ans += ha[len][f];
		if((arr[i] * (ll)pow(10.0l, len)) % k == f) ans--;
	}
	cout << ans << "\n";
	return 0;
}
