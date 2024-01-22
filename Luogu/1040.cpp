#include <iostream>
#include <vector>
using namespace std;

int n;
int arr[32] = {0};
int dp[32][32] = {0};
int mid[32][32] = {0};

int dfs(int l, int r);
void pre(int l, int r);

int main(){
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> arr[i];
	}
	int ans = dfs(1, n);
	cout << ans << "\n";
	pre(1, n);
	cout << "\n";
	return 0;
}

int dfs(int l, int r){
	if(dp[l][r] != 0) return dp[l][r];
	if(l == r) {
		dp[l][r] = arr[l];
		mid[l][r] = l;
		return dp[l][r];
	}
	if(l > r) return 0;
	int maxv = -1;
	int maxn = -1;
	for(int i = l; i <= r; i++){
		int now;
		int lv = dfs(l, i - 1);
		int rv = dfs(i + 1, r);
		if(lv == 0 && rv == 0) now = arr[i];
		else now = ((lv == 0)? 1: lv) * ((rv == 0)? 1: rv) + arr[i];
		if(now > maxv){
			maxv = now;
			maxn = i;
		}
	}
	mid[l][r] = maxn;
	return dp[l][r] = maxv;
}

void pre(int l, int r){
	if(mid[l][r] == 0) return;
	int a;
	cout << (a = mid[l][r]) << " ";
	pre(l, a - 1);
	pre(a + 1, r);
}





