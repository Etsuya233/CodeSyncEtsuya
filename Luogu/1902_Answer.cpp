#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
const int N = 1010;
int n, m, map[N][N], l, r, mid, x, y;
int dx[4] = {-1, 1, 0, 0}, dy[4] = {0, 0, -1, 1};
bool flag = 0, vis[N][N];
int read() {
	int s = 0, w = 1;
	char ch = getchar();
	while(!isdigit(ch)) {if(ch == '-') w = -1;ch = getchar();}
	while(isdigit(ch)) {s = s * 10 + ch - '0';ch = getchar();}
	return s * w;
}
void dfs(int xx, int yy) {
	if(xx == n) {flag = 1;return;}
	for(int i = 0; i < 4; i++) {
		x = xx + dx[i], y = yy + dy[i];
		if(x >= 1 && x <= n && y >= 1 && y <= m && map[x][y] <= mid && !vis[x][y]) {
			vis[x][y] = 1;
			dfs(x, y);
			vis[x][y] = 0;
			if(flag) break;
		}
	}
}
bool check(int x) {
	flag = 0;
	memset(vis, 0, sizeof(vis));
	dfs(1, 1);
	if(flag) return 1;
	return 0;
}
int main() {
	n = read(), m = read();
	for(int i = 1; i <= n; i++) 
		for(int j = 1; j <= m; j++)
			map[i][j] = read(), r = max(r, map[i][j]);
	while(l + 1 < r) {
		mid = (l + r) >> 1;
		if(check(mid)) r = mid;
		else l = mid;
	}
	printf("%d\n", r);
	return 0;
}