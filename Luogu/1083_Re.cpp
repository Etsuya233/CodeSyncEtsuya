#include <iostream>
#include <cstring>
using namespace std;

typedef long long ll;

typedef struct OrderSturct{
	ll d = 0, s = 0, t = 0;
} order;

ll n, m;
ll classroom[1000010];
ll pre[1000010];
order arr[1000010];

bool check(ll mid);

int main(){
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> classroom[i];
	}
	for(int i = 1; i <= m; i++){
		cin >> arr[i].d >> arr[i].s >> arr[i].t;
	}
	ll l = 1, r = n + 5, mid;
	while(l < r){
		mid = (l + r) / 2;
		if(check(mid)){
			l = mid + 1;
		} else {
			r = mid;
		}
	}
	if(l <= n + 1){
		cout << "-1" << "\n" << l;
	} else {
		cout << "0";
	}
	return 0;
}

bool check(ll mid){
	memset(pre, 0, sizeof(pre));
	for(int i = 1; i <= mid; i++){
		pre[arr[i].s] += arr[i].d;
		pre[arr[i].t + 1] -= arr[i].d;
	}
	for(int i = 1; i <= n; i++){
		pre[i] += pre[i - 1];
		if(pre[i] > classroom[i]) return false;
	}
	return true;
}
