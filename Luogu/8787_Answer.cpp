#include <iostream>
#include <cmath>
using namespace std;
typedef long long ll;
ll h[1000003],cnt[1000003];

ll max(ll a, ll b){
	return a > b ? a : b;
}

int main(){
    int n;
    cin >> n;
    ll maxCnt = -1,ans = 0;
    for(int i = 0; i < n; ++i){
    	cin >> h[i];
    	ll temp = h[i];
    	while(temp - 1){
    		++cnt[i];
    		temp = sqrtl(temp / 2 + 1);
		}
		maxCnt = max(maxCnt, cnt[i]);
	}
	for(int i = maxCnt; i > 0; --i){
		for(int j = 0; j < n; ++j){
			if(cnt[j] == i){
				if(h[j] != h[j + 1])
					++ans;
				--cnt[j];
				h[j] = sqrtl(h[j] / 2 + 1);
			}
		}
	}
	printf("%lld",ans);
	return 0;
}
