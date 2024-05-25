#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;
typedef struct Line {
	ll l, r;
} li;

ll n;
li arr[100005];

bool cmpLine(li a, li b);

int main(){
	cin >> n;
	for(ll i = 1; i <= n; i++){
		cin >> arr[i].l >> arr[i].r;
	}
	sort(arr + 1, arr + 1 + n, cmpLine);
	ll l = arr[1].l, r = arr[1].r, ans = arr[1].r - arr[1].l + 1;
	for(ll i = 2; i <= n; i++){
		if(arr[i].l > r){
			ans -= arr[i].l - r - 1;	
		}
		if(arr[i].r > r){
			ans += arr[i].r - r;
			r = arr[i].r;
		}
	}
	cout << ans << "\n";
	return 0;
}

bool cmpLine(li a, li b){
	if(a.l != b.l) return a.l < b.l;
	return a.r < b.r;
}
