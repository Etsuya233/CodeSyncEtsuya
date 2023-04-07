#include <cstdio>

int main(){
	int sum[105][105] = {0};
	int map[105][105] = {0};
	int n, m, max = 1;
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			scanf("%d", &map[i][j]);
			sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + map[i][j];
			for(int k = i - 1, l = j - 1; k > 0 && l > 0; k--, l--){
				if((sum[i][j] - sum[k - 1][j] - sum[i][l - 1] + sum[k - 1][l - 1]) == (i - k + 1) * (i - k + 1)){
					if(i - k + 1 > max) max = i - k + 1;
				}
			}
		}
	}
	printf("%d", max);
}