#include <iostream>
#include <climits>
using namespace std;

typedef long long ll;

ll l, k;
ll arr[100050];

ll check(ll n);

int main(){
	cin >> l >> k;
	for(int i = 1; i <= l; i++){
		cin >> arr[i];
	}
	ll l = 1, r = LLONG_MAX - 10, mid;
	ll maxRes, minRes;
	while(l < r){
		mid = (l + r) / 2;
		if(check(mid) <= k){//假如我做的题少了或刚刚好
			r = mid;
		} else {//假如多了
			l = mid + 1;
		}
	}
	minRes = l;
	l = 1;
	r = LLONG_MAX - 10;
	while(l < r){
		mid = (l + r) / 2;
		if(check(mid) <= k - 1){
			r = mid;
		} else {
			l = mid + 1;
		}
	}
	maxRes = l - 1;
	ll count = check(minRes);
	if(count != k) cout << -1;
	else cout << minRes << " " << maxRes;
	return 0;
}

ll check(ll n){
	ll cnt = 0, now = 0;
	for(int i = 1; i <= l; i++){
		now += arr[i];
		if(now >= n){
			cnt++;
			now = 0;
		} else if(now < 0){
			now = 0;
		}
	}
	return cnt;
}
