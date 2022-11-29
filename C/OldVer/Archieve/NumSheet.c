#include <stdio.h>
int main(){
	int a,b,cnt=0,sum=0;
	scanf("%d %d",&a,&b);
	while(a<=b){
		sum+=a;
		cnt++;
		if(a<10&&a>=0){
			printf("    %d",a);
		}else if((a>=10&&a<=99)||(a>=-9&&a<=-1)){
			printf("   %d",a);
		}else if(a==100||(a<=-10&&a>=-99)){
			printf("  %d",a);
		}else{
			printf(" %d",a);
		}
		if(cnt==5){
			printf("\n");
			cnt=0;
		}
		a++;
	}
	if(cnt==0){
		printf("Sum = %d",sum);
	}else{
		printf("\nSum = %d", sum);
	}
	return 0;
}
