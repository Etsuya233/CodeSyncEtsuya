#include <iostream>
#include <algorithm>
using namespace std;

typedef struct Object{
	int v, w, g;
} obj;

int dp[2][1002] = {0};
int m, n;
obj arr[1002];
int maxgroup = -1;

bool cmpObject(obj a, obj b);

int main(){
	cin >> m >> n;
	for(int i = 1; i <= n; i++){
		cin >> arr[i].w >> arr[i].v >> arr[i].g;
		maxgroup = max(arr[i].g, maxgroup);
	}
	arr[0].g = 0;
	sort(arr + 1, arr + 1 + n, cmpObject);
	for(int i = 1; i <= n; i++){
		int nowg = arr[i].g;
		if(nowg != arr[i - 1].g){
			for(int j = 0; j <= m; j++){
				dp[nowg % 2][j] = dp[(nowg - 1) % 2][j];
//				cout << "copy " << nowg << " " << i << " " << dp[(nowg - 1) % 2][i] << "\n";
			}
		}
		for(int j = arr[i].w; j <= m; j++){
			dp[nowg % 2][j] = max(dp[(nowg - 1) % 2][j - arr[i].w] + arr[i].v, dp[nowg % 2][j]);
		}
	}
	cout << dp[maxgroup % 2][m];
	return 0;
}

bool cmpObject(obj a, obj b){
	if(a.g == b.g){
		if(a.v == b.v){
			return a.w < b.w;
		}
		return a.v < b.v;
	}
	return a.g < b.g;
}
