#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

typedef long long ll;

ll n;
ll arr[200005] = {0}, cut[200005] = {0};
ll ans = 0;
ll maxCut = 0;

int main(){
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> arr[i];
		ll temp = arr[i];
		while(temp > 1){
			temp = sqrtl(temp / 2 + 1);
			cut[i] ++;
		}
		maxCut = max(maxCut, cut[i]);
	}
	for(int i = maxCut; i > 0; i--){
		for(int j = 1; j <= n; j++){
			if(cut[j] == i){
				if(arr[j] != arr[j + 1]){
					ans++;
				}
				arr[j] = sqrtl(arr[j] / 2 + 1);
				cut[j] --;
			}
		}
	}
	cout << ans;
	return 0;
}
