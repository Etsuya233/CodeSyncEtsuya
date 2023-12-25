#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int n, m;
int arr[100050];
int Min[100050][22];
int ans[100050];

int query(int l, int r);
void calc();

int main(){
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> arr[i];
	}
	calc();
	for(int i = 0; i < m; i++){
		int a, b;
		cin >> a >> b;
		ans[i] = query(a, b);
	}
	for(int i = 0; i < m; i++){
		cout << ans[i] << " ";
	}
	return 0;
}

void calc(){
	for(int i = 1; i <= n; i++){
		Min[i][0] = arr[i];
	}
	for(int j = 1; j <= 21; j++){
		for(int i = 1; i + (1 << j) - 1 <= n; i++){
			Min[i][j] = min(Min[i][j - 1], Min[i + (1 << (j - 1))][j - 1]);
		}
	}
}

int query(int l, int r){
	int k = log2(r - l + 1);
	//x + 2^k - 1 = r ==> x = r - 2^k + 1
	return min(Min[l][k], Min[r - (1 << k) + 1][k]);
}
