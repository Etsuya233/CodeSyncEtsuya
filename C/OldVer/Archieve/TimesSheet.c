#include <stdio.h>
int main(){
	//	int a=1, b=1;
	//	for(;a<=9;a++){
	//		b =1;
	//		for(;b<=a;b++){
	//			printf("%d * %d = %d ", b, a, a*b);
	//			if (a * b < 10){
	//				printf(" ");
	//			}
	//		}
	//		printf("\n");
	//	}
	
	int a=1,b=1,n;
	scanf("%d",&n);
	for(;a<=n;a++){
		for(b=1;b<=a;b++){
			printf("%d*%d=%d  ",b,a,a*b);
			if(a*b<10){
				printf(" ");
			}
		}
		printf("\n");
	}
	
	
	return 0;
}
