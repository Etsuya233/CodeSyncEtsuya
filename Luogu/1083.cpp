#include <cstdio>

int n, m;
int arr[1000005];

int main(){
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++){
		scanf("%d", &arr[i]);
	}
	for(int i = 0; i < m; i++){
		int d, s, t;
		scanf("%d%d%d", &d, &s, &t);
		for(int j = s; j <= t; j++){
			arr[j] -= d;
			if(arr[j] < 0){
				printf("-1\n%d", i + 1);
				return 0;
			}
		}
	}
	printf("0");
}