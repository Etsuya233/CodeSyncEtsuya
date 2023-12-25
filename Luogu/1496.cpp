#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;

int n;
ll l[20005], r[20005];
ll num[60015];
ll dis[60015] = {0};
ll dp[60015] = {0};

int main(){
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> l[i] >> r[i];
		num[i * 3] = l[i];
		num[i * 3 + 1] = r[i] - 1;
		num[i * 3 + 2] = r[i];
	}
	sort(num, num + 3 * n);
	ll reu = unique(num, num + 3 * n) - num;
	for(int i = 0; i < n; i++){
		ll dl = lower_bound(num, num + reu, l[i]) - num;
		ll dr = lower_bound(num, num + reu, r[i] - 1) - num;
		dis[dl] = l[i];
		dis[dr] = r[i] - 1;
		dp[dl] += 1;
		dp[dr + 1] -= 1;
	}
	for(int i = 1; i < 60015; i++){
		dp[i] += dp[i - 1];
	}
	ll ans = 0;
	ll cnt = 0;
	for(int i = 0; i < reu + 1; i++){
		if(dp[i]) cnt++;
		else if(cnt > 0){
			ans += dis[i - 1] - dis[i - cnt] + 1;
			cnt = 0;
		}
	}
	cout << ans;
	return 0;
}
