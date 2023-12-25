#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

typedef long long ll;

typedef struct OreBlock{
	ll w, v;
} ore;

ll n, m, s;
ore arr[200005];
ll range[200005][2];
ll pre[200005] = {0};
ll preNum[200005] = {0};

void calcPre(ll mid);

ll check();

int main(){
	cin >> n >> m >> s;
	for(int i = 1; i <= n; i++){
		cin >> arr[i].w >> arr[i].v;
	}
	for(int i = 1; i <= m; i++){
		cin >> range[i][0] >> range[i][1];
	}
	ll l = 0, r = 1000005, mid;
	//mid<=s
	while(l < r){
		mid = (l + r) / 2;
		calcPre(mid);
		if(check() > s){
			l = mid + 1;
		} else {
			r = mid;
		}
	}
	calcPre(l);
	ll resr = check();
	//mid>=s
	calcPre(l - 1);
	ll resl = check();
	cout << min(labs(s - resl), labs(resr - s));
	return 0;
}

void calcPre(ll mid){
	pre[0] = 0;
	for(int i = 1; i <= n; i++){
		pre[i] = pre[i - 1] + ((arr[i].w >= mid)? arr[i].v: 0);
		preNum[i] = preNum[i - 1] + ((arr[i].w >= mid)? 1: 0);
	}
}

ll check(){
	ll y = 0;
	for(int i = 1; i <= m; i++){
		y += ((preNum[range[i][1]] - preNum[range[i][0] - 1]) * (pre[range[i][1]] - pre[range[i][0] - 1]));
	}
	return y;
}
