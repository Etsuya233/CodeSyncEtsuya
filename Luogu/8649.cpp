#include <iostream>
using namespace std;

int n, k;
long long arr[100005];
long long pre[100005] = {0};
long long preMod[100005] = {0};
long long ans = 0;

int main(){
	cin >> n >> k;
	for(int i = 1; i <= n; i++){
		cin >> arr[i];
		pre[i] = pre[i - 1] + arr[i];
		preMod[(pre[i] % k)] ++;
	}
	preMod[0] ++;
	for(int i = 0; i < k; i++){
		if(preMod[i] > 1)
			ans += preMod[i] * (preMod[i] - 1) / 2;
	}
	cout << ans;
	return 0;
}

