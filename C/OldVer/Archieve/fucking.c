#include <stdio.h>
int main(){
	int a,i,j,k,cnt=0;
	scanf("%d",&a);
	i=a;
	for(;i<=a+3;i++){
		j=a;
		for(;j<=a+3;j++){
			k=a;
			for(;k<=a+3;k++){
				if(i!=j&&i!=k&&j!=k){
					printf("%d",100*i+10*j+k);
					cnt++;
					if(cnt==6){
						printf("\n");
						cnt=0;
					}else if(cnt!=6){
						printf(" ");
					}
				}
			}
		}
	}
	
	return 0;
}
