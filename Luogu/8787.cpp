#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

typedef long long ll;

ll arr[200005];
ll ans = 0;
ll n;

int main(){
//	cin >> n;
//	for(int i = 1; i <= n; i++){
//		cin >> arr[i];
//	}
	n = 20000;
	for(ll i = 1; i <= 20000; i++){
		arr[i] = 100000000000000 + i;
	}
	while(true){
		ll maxNum = 1, maxLoc = 0, maxSpan = 0;
		for(int i = 1; i <= n; i++){
			if(arr[i] > maxNum){
				maxNum = arr[i];
				maxLoc = i;
				maxSpan = 1;
			} else if(arr[i] == maxNum && maxLoc + maxSpan == i){
				maxSpan++;
			}
		}
		if(maxNum == 1) break;
		else ans++;
		int r = sqrtl(maxNum / 2 + 1);
		for(int i = maxLoc; i < maxLoc + maxSpan; i++){
			arr[i] = r;
		}
	}
	cout << ans;
	return 0;
}
