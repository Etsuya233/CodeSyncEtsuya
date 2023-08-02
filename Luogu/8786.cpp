#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
int ans = 0;
int moda = 1000000007;
int vis[105][105][105];

int sto[15];

int dfs(int leftn, int leftm, int sake, int last);
int dfs2(int leftn, int leftm, int sake, int depth, int last);

int main(){
	cin >> n >> m;
	fill(vis[0][0], vis[0][0] + 105 * 105 * 105, -1); //memset
	dfs(n, m, 2, 0);
	cout << ans;
	return 0;
}

int dfs(int leftn, int leftm, int sake, int last){
	if(sake < 0 || leftn < 0 || leftm < 0) return 0;
	if(sake == 0 && leftm > 0) return 0;
	if(sake > leftm) return 0;
	if(sake == 0 && leftm == 0 && leftn == 0 && last == 0){
		ans = (ans + 1) % moda;
		return 1;
	}
	if(vis[leftn][leftm][sake] != -1){
		ans = (ans + vis[leftn][leftm][sake]) % moda;
		return vis[leftn][leftm][sake];
	};
	//hana
	int a = dfs(leftn, leftm - 1, sake - 1, 0);
	//mise
	int b = dfs(leftn - 1, leftm, sake * 2, 1);
	return vis[leftn][leftm][sake] = (a + b) % moda;
}

int dfs2(int leftn, int leftm, int sake, int depth, int last){
	if(sake < 0 || leftn < 0 || leftm < 0) return 0;
	if(sake == 0 && leftm > 0) return 0;
	if(sake > leftm) return 0;
	if(sake == 0 && leftm == 0 && leftn == 0 && last == 0){
		ans = (ans + 1) % moda;
		for(int i = 0; i < 15; i++){
			cout << sto[i];
		}
		cout << "\n";
		return 1;
	}
	if(vis[leftn][leftm][sake] != -1){
		ans += vis[leftn][leftm][sake];
		return vis[leftn][leftm][sake];
	};
	//hana
	sto[depth] = 0;
	int a = dfs2(leftn, leftm - 1, sake - 1, depth + 1, 0);
	//mise
	sto[depth] = 1;
	int b = dfs2(leftn - 1, leftm, sake * 2, depth + 1, 1);
	return vis[leftn][leftm][sake] = a + b;
}
