#include <iostream>
#include <vector>
using namespace std;

int n;
int arr[204] = {0};
int pre[204] = {0};
int dpmax[204][204] = {0};
int dpmin[204][204] = {0};

int dfsmax(int l, int r);
int dfsmin(int l, int r);

int main(){
	cin >> n;
	//input
	for(int i = 1; i <= n; i++){
		cin >> arr[i];
		arr[i + n] = arr[i];
	}
	//pre
	for(int i = 1; i <= 2 * n; i++){
		pre[i] += pre[i - 1] + arr[i];
	}
	//dp
	dfsmax(1, 2 * n);
	dfsmin(1, 2 * n);
	//ans
	int ansmax = 0, ansmin = 0x3fffffff;
	for(int i = 1; i <= n; i++){
		ansmax = max(ansmax, dpmax[i][n + i - 1]);
		ansmin = min(ansmin, dpmin[i][n + i - 1]);
	}
	cout << ansmin << "\n" << ansmax;
	return 0;
}

int dfsmax(int l, int r){
	if(dpmax[l][r]) return dpmax[l][r];
 	cout << l << " " << r << "\n";
	if(l >= r) return dpmax[l][r] = 0;
	int res = 0;
	for(int i = l; i < r; i++){
		res = max(res, dfsmax(l, i) + dfsmax(i + 1, r) + pre[r] - pre[l - 1]);
	}
	return dpmax[l][r] = res;
}

int dfsmin(int l, int r){
	if(dpmin[l][r]) return dpmin[l][r];
	if(l >= r) return dpmin[l][r] = 0;
	int res = 0x3fffffff;
	for(int i = l; i < r; i++){
		res = min(res, dfsmin(l, i) + dfsmin(i + 1, r) + pre[r] - pre[l - 1]);
	}
	return dpmin[l][r] = res;
}
