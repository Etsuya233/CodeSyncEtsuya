#include <iostream>
#include <cstring>
using namespace std;

int n, m;
int arr[1010][1010] = {0};
int vis[1010][1010] = {0};
int xx[4] = {0, 1, 0, -1};
int yy[4] = {-1, 0, 1, 0};
int flag = 0;
int cnt = 0;

void dfs(int mid, int a, int b, int layer);

int main(){
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			cin >> arr[i][j];
		}
	}
	int l = 0, r = 1002, mid;
	while(l + 1 < r){
		memset(vis, 0, sizeof(vis));
		vis[1][1] = 1;
		flag = 0;
		mid = (l + r) / 2;
		dfs(mid, 1, 1, 0);
		if(flag) r = mid;
		else l = mid;
	}
	cout << r;
}

void dfs(int mid, int a, int b, int layer){
//	if(cnt == 10000){
//		cout << "here!\n";
//	}
//	cout << "Working: cnt: " << cnt << " mid:" << mid << " a, b : " << a << "," << b << " layer: " << layer << "\n";
    cnt ++;
	if(a == n){
		flag = 1;
		return;
	}
	for(int i = 0; i < 4; i++){
        int aa = a + yy[i], bb = b + xx[i];
		if(aa >= 1 && aa <= n && bb >= 1 && bb <= m && vis[aa][bb] == 0 && arr[aa][bb] <= mid){
			vis[aa][bb] = 1;
			dfs(mid, aa, bb, layer + 1);
			if(flag) return;
		}
	}
}

/*
不太明白，为什么这道题不用加上 vis[a + yy[i]][b + xx[i]] = 0;
*/