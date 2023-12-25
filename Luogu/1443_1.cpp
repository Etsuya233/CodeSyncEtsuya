#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
using namespace std;

typedef struct Position{
	double x, y;
} po;

int n;
po arr[20];
double dd[16][16] = {0};
double dp[16][1 << 16];//现在在i上，走过的路径为j时的最短距离。
double ans = 0x7fffffff;

double dist(po a, po b);

int main(){
	scanf("%d", &n);
	arr[0].x = 0;
	arr[0].y = 0;
	memset(dp, 127, sizeof(dp));//给浮点数赋值无限大
	for(int i = 1; i <= n; i++){
		scanf("%lf%lf", &arr[i].x, &arr[i].y);
	}
	for(int i = 0; i <= n; i++){
		for(int j = 0; j <= n; j++){
			dd[i][j] = dist(arr[i], arr[j]);
		}
	}
	//初始化
	for(int i = 1; i <= n; i++){
		dp[i][1 << (i - 1)] = dd[0][i];
	}
	for(int k = 0; k < (1 << n); k++){
		for(int i = 1; i <= n; i++){
			if((k & (1 << (i - 1))) == 0) continue;
			for(int j = 1; j <= n; j++){
				if(i == j) continue;
				if((k & (1 << (j - 1))) == 0) continue;
				dp[i][k] = min(dp[i][k], dp[j][k - (1 << (i - 1))] + dd[i][j]);
//				printf("%.4f\n", dp[i][k]);
			}
		}
	}
	for(int i = 1; i <= n; i++){
		ans = min(dp[i][(1 << n) - 1], ans);
	}
	printf("%.2f\n", ans);
	return 0;
}

double dist(po a, po b){
	return 1.0 * sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}


