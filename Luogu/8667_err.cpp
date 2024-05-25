#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;

ll n;
ll a[100005], b[100005], c[100005];
ll cb[100005], cc[100005];

int main(){
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	for(int i = 1; i <= n; i++) cin >> b[i];
	for(int i = 1; i <= n; i++) cin >> c[i];
	sort(a + 1, a + 1 + n);
	sort(b + 1, b + 1 + n);
	sort(c + 1, c + 1 + n);
	for(int i = 1; i <= 100000; i++){
		cb[i] = upper_bound(b + 1, b + 1 + n, i) - b;
		cc[i] = upper_bound(c + 1, c + 1 + n, i) - c;
	}
	ll ans = 0;
	for(int i = 1; i <= n; i++){
		for(int j = cb[a[i]]; j <= n; j++){
			if(cc[b[j]] <= n) ans += n - cc[b[j]] + 1;
		}
	}
	cout << ans << "\n";
	return 0;
}
