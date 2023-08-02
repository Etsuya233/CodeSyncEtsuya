#include <iostream>
using namespace std;

typedef long long ll;

const ll INF = 1e9;
ll target;

ll C(int below, int up){
	ll ret = 1;
	for(int i = below, j = 1; j <= up; i--, j++){
		ret = ret * i / j;
		if(ret > INF) return ret;
	}
	return ret;
}

int main(){
	cin >> target;
	if(target == 1){
		cout << 1;
		return 0;
	}
	for(int i = 16; i >= 0; i--){
		ll l = 2 * i, r = INF;
		while(l <= r){
			ll mid = (l + r) / 2;
			ll cres = C(mid, i);
			if(cres == target){
				cout << (mid * (mid + 1) / 2 + i + 1);
				return 0;
			} else if(cres > target){
				r = mid - 1;
			} else {
				l = mid + 1;
			}
		}
	}
	return 0;
}
