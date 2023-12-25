#include <iostream>
#include <cstring>
using namespace std;

int n;
int arr[210] = {0};

int pre[210] = {0};
int maxx[210][210];
int minn[210][210];

int getmax(int l, int r);
int getmin(int l, int r);

int main(){
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> arr[i];
		arr[n + i] = arr[i];
	}
	for(int i = 1; i <= 2 * n; i++){
		pre[i] = pre[i - 1] + arr[i];
	}
	memset(maxx, -1, sizeof(maxx));
	memset(minn, -1, sizeof(minn));
	int ansmin = 0x3fffffff;
	int ansmax = -2;
	for(int i = 1; i <= n; i++){
		ansmin = min(ansmin, getmin(i, i + n - 1));
		ansmax = max(ansmax, getmax(i, i + n - 1));
	}
	cout << ansmin << "\n" << ansmax << "\n";
	return 0;
}

int getmax(int l, int r){
	if(maxx[l][r] != -1) return maxx[l][r];
	if(l == r) return maxx[l][r] = 0;
	int ans = -1;
	for(int i = l; i < r; i++){
		ans = max(getmax(l, i) + getmax(i + 1, r) + pre[r] - pre[l - 1], ans);
	}
	return maxx[l][r] = ans;
}

int getmin(int l, int r){
	if(minn[l][r] != -1) return minn[l][r];
	if(l == r) return minn[l][r] = 0;
	int ans = 0x3fffffff;
	for(int i = l; i < r; i++){
		ans = min(getmin(l, i) + getmin(i + 1, r) + pre[r] - pre[l - 1], ans);
	}
	return minn[l][r] = ans;
}
