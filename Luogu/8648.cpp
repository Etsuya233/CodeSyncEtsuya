#include <iostream>
#include <algorithm>
using namespace std;

int n;
int arr[10005][10005] = {0};
int ii = 0x3fffffff, jj = 0x3ffffff, iii = 0, jjj = 0;
long long ans = 0;

int main(){
	cin >> n;
	for(int i = 0; i < n; i++){
		int i1, j1, i2, j2;
		cin >> i1 >> j1 >> i2 >> j2;
		i2--;
		j2--;
		ii = min(ii, i1);
		jj = min(jj, j1);
		iii = max(iii, i2);
		jjj = max(jjj, j2);
		arr[i1][j1] ++;
		arr[i1][j2 + 1] --;
		arr[i2 + 1][j1] --;
		arr[i2 + 1][j2 + 1] ++;
	}
	for(int i = ii; i <= iii; i++){
		for(int j = jj; j <= jjj; j++){
			arr[i][j] = (i? arr[i - 1][j]: 0) + (j? arr[i][j - 1]: 0) - (i > 0 && j > 0? arr[i - 1][j - 1]: 0) + arr[i][j];
			if(arr[i][j]){
				ans++;
			}
		}
	}
	cout << ans;
	return 0;
}
