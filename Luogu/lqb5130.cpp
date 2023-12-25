#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;

ll n, m, q;
ll w[55] = {0}, v[55] = {0};
ll dp[2 * (int)1e5 + 10];
ll days[2 * (int)1e5 + 10];
ll ho[2 * (int)1e5 + 10];
ll maxho = 0;

int main(){
	cin >> n >> m >> q;
	ho[0] = 0;
	for(int i = 1; i <= q; i++){
		cin >> ho[i];
	}
	ho[q + 1] = n + 1;
	for(int i = 1; i <= q + 1; i++){
		days[i - 1] = ho[i] - ho[i - 1] - 1;
		maxho = max(maxho, days[i - 1]);
	}
	for(int i = 1; i <= m; i++){
		int a;
		cin >> a >> v[i];
		w[i] = (1 << a);
	}
	//dp
	for(int i = 1; i <= m; i++){
		for(int j = 0; j <= maxho; j++){
			if(j >= w[i]) dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
		}
	}
	//query
	ll ans = 0;
	for(int i = 0; i <= q; i++){
//		cout << dp[days[i]] << "\n";
		ans += dp[days[i]];
	}
	cout << ans;
	return 0;
}
