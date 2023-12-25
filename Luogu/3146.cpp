#include <iostream>
#include <cstring>
using namespace std;

int n;
int arr[250] = {0};

int pre[250] = {0};
int maxx[250][250];
int anss = -1;

int getmax(int l, int r);

int main(){
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> arr[i];
		anss = max(anss, arr[i]);
		pre[i] = pre[i - 1] + arr[i];
	}
	memset(maxx, -1, sizeof(maxx));
	getmax(1, n);
	cout << anss << "\n";
	return 0;
}

int getmax(int l, int r){
	if(maxx[l][r] != -1) return maxx[l][r];
	if(l == r) return maxx[l][r] = arr[l];
 	int ans = 0;
// 	cout << l << " " << r << " " << maxx[l][r] << "\n";
	for(int i = l; i < r; i++){
		int a = getmax(l, i);
		int b = getmax(i + 1, r);
//		ans = max(max(a, b), ans);
		if(a != 0 && a == b) ans = max(ans, a + 1);
	}
	anss = max(anss, ans);
	return maxx[l][r] = ans;
}
