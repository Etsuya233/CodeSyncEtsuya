#include <stdio.h>
int isP(int num);
int main(){
	int range=15;
//	scanf("%d",&range);
	
	int a;
	int prime[range];
	for(a=0;a<range;a++){
		prime[a]=1;
	}
	
	int num=0;
	for(num=0;num<range;num++){
		if(isP(num)==0){
			prime[num]=0;
		}
	}
	
	a=0;
	for(a=1;a<range;a++){
		if(prime[a]==1){
			printf("%d\t", a);
		}
	}
	
	return 0;
}
int isP(int num){
	int ret=1;
	for(int a=2;a<num;a++){
		if(num%a==0){
			ret=0;
			break;
		}
		
	}
	return ret;
}
