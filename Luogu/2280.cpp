#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
int maxi = 0, maxj = 0;
int arr[5005][5005] = {0};
int res = 0;

int main(){
	cin >> n >> m;
	for(int i = 0; i < n; i++){
		int a, b, c;
		cin >> a >> b >> c;
		arr[a + 1][b + 1] = c;
		maxi = max(maxi, a);
		maxj = max(maxj, b);
	}
	for(int i = 1; i <= maxi + 1; i++){
		for(int j = 1; j <= maxj + 1; j++){
			arr[i][j] = arr[i - 1][j] + arr[i][j - 1] - arr[i - 1][j - 1] + arr[i][j];
		}
	}
    int mi = m, mj = m;
    if(m > maxi + 1) mi = maxi + 1;
    if(m > maxj + 1) mj = maxj + 1;
	for(int i = mi; i <= maxi + 1; i++){
		for(int j = mj; j <= maxj + 1; j++){
			res = max(res, arr[i][j] - arr[i - mi][j] - arr[i][j - mj] + arr[i - mi][j - mj]);
		}
	}
	cout << res;
}