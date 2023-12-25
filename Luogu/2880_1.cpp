#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

int n, m;
int arr[100050];
int Max[100050][22] = {0};
int Min[100050][22] = {0};

int judge(int a, int b);
void calc();

int main(){
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++){
		scanf("%d", &arr[i]);
	}
	calc();
	int a, b;
	for(int i = 0; i < m; i++){
		scanf("%d%d", &a, &b);
		printf("%d\n", judge(a, b));
	}
	return 0;
}

void calc(){
	//初始化，为Max[i][0]赋值（i+2^0：即本身）
	//其实这里可以用Max[i][0]来直接存值！
	for(int i = 1; i <= n; i++){
		Max[i][0] = arr[i];
		Min[i][0] = arr[i];
	}
	//计算Max数组
	for(int j = 1; j <= 21; j++){
		for(int i = 1; i + (1 << j) - 1 <= n; i++){
			Max[i][j] = max(Max[i][j - 1], Max[i + (1 << (j - 1))][j - 1]);
			Min[i][j] = min(Min[i][j - 1], Min[i + (1 << (j - 1))][j - 1]);
		}
	}
}

int judge(int l, int r){
	int k = log2(r - l + 1);
	return max(Max[l][k], Max[r - (1 << k) + 1][k]) - min(Min[l][k], Min[r - (1 << k) + 1][k]);
}
