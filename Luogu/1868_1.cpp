#include <iostream>
#include <algorithm>
using namespace std;

typedef struct Line{
	int l, r, a;
} li;

int n;
li arr[150050];
int dp[3000050] = {0};
int maxDis = 0;

bool cmpLine(li a, li b);

int main(){
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> arr[i].l;
		cin >> arr[i].r;
		arr[i].a = arr[i].r - arr[i].l + 1;
		maxDis = max(maxDis, arr[i].r);
	}
	sort(arr, arr + n, cmpLine);
	//dp
	int now = 0;
	for(int i = 1; i <= maxDis; i++){
		dp[i] = dp[i - 1];
		while(arr[now].r <= i && now < n){
			dp[i] = max(dp[i], ((arr[now].l <= 0)? 0: dp[arr[now].l - 1]) + arr[now].a);
			now++;
		}
	}
	cout << dp[maxDis];
	return 0;
}

bool cmpLine(li a, li b){
	if(a.r < b.r) return true;
	if(a.r == b.r && a.l < b.l) return true;
	return false;
}
