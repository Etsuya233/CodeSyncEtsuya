#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;
ll n;
ll a[100005], b[100005], c[100005];
ll pre[100005] = {0}; 

int main(){
	cin >> n;
	for(int i = 0; i < n; i++) cin >> a[i];
	for(int i = 0; i < n; i++) cin >> b[i];
	for(int i = 0; i < n; i++) cin >> c[i];
	sort(a, a + n);
	sort(b, b + n);
	sort(c, c + n);
	for(int i = 0; i < n; i++){
		int m = upper_bound(c, c + n, b[i]) - c;
		pre[i] = n - m;
	}
	for(int i = n - 1; i >= 0; i--){
		pre[i] += pre[i + 1];
	}
	ll ans = 0;
	for(int i = 0; i < n; i++){
		int m = upper_bound(b, b + n, a[i]) - b;
		ans += pre[m];
	}
	cout << ans << "\n";
	return 0;
}
