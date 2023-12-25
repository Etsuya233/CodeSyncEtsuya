#include <cstdio>
#include <algorithm>
#include <functional>
using namespace std;

int main(){
	int arr[100050] = {0};
	int dp[100050] = {0};
	int ma[100050] = {0};
	int n = 0, len = 1, m = 1;
	while(~scanf("%d", &arr[n++]));
	n--;
	dp[0] = arr[0];
	ma[0] = dp[0];
	for(int i = 1; i < n; i++){
		auto it = upper_bound(dp, dp + len, arr[i], greater<int>());
		if(it - dp >= len) len++;
		*it = arr[i];
		it = lower_bound(ma, ma + m, arr[i]);
		if(it - ma >= m) m++;
		*it = arr[i];
	}
	printf("%d\n%d", len, m);
	return 0;
}
