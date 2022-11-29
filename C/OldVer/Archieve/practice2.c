#include <stdio.h>
int main(){
	int a, big, i, j, k, cnt=0;
	scanf("%d", &a);
	big = a+3;
	i = a;
	for (;i <= big;i ++){
		j=a;
		for(;j <= big; j ++){
			k =a;
			for(; k <= big; k++){
				if(i!=j && i!=k && j!=k){
					printf("%d%d%d ", i,j,k);
					cnt ++;
					if(cnt==6){
						printf("\n");
						cnt =0;
					}
				}
			}
		}
	}
	
	
	
	return 0;
}
