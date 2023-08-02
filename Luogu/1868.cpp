#include <iostream>
#include <algorithm>
using namespace std;

typedef struct Spanning{
	int l, r, a;
} span;

int n;
span arr[150005];
int dp[150005] = {0};
span tempa;

int lower_bound_fuck(int l, int r, int target);
bool cmpSpan(span a, span b);

int main(){
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> tempa.l >> tempa.r;
		tempa.a = tempa.r - tempa.l + 1;
		arr[i] = tempa;
	}
	sort(arr, arr + n, cmpSpan);
	for(int i = 0; i < n; i++){
		dp[i] = max(arr[i].a, dp[i - 1]);
		int loc = lower_bound_fuck(0, i, arr[i].l);
		dp[i] = max(dp[i], dp[loc - 1] + arr[i].a);
	}
	cout << dp[n - 1];
}

bool cmpSpan(span a, span b){
	if(a.r < b.r) return true;
	else return false;
}

int lower_bound_fuck(int l, int r, int target){
	int mid = (l + r) / 2;
	while(l < r){
		if(arr[mid].r >= target){
			r = mid;
		} else {
			l = mid + 1;
		}
	}
	return l;
}