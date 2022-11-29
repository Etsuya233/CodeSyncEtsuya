#include <stdio.h>
int main(){
	int a, n, cnt = 0, sum = 0, que = 0;
	scanf("%d %d", &a, &n);
	for(cnt = n; cnt > 0; cnt --){
		que = que * 10 + a;
		sum += que;
	}
	printf("%d", sum);
	
	return 0;
}
