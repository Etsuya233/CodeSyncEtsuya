#include <stdio.h>
int max(int,int);
int main(void){
	int a1,a2,b1,b2;
	scanf("%d/%d",&a1,&b1);
	scanf("%d/%d",&a2,&b2);

	// Get the smallest common timer
	int m=max(b1,b2);
	while(1){
		if(m%b1==0 && m%b2==0){
			break;
		}else{
			m++;
		}
	}

	int sum1=(m/b1*a1+m/b2*a2);

	int cnt;
	int m1=max(sum1,m);
	//Get the GCD
	for(;m1>0;m1--){
		if(sum1%m1==0 && m%m1==0){
			break;
		}
	}

	if((sum1/m1)%(m/m1)==0){
		printf("%d", sum1/m);
	}else{
		printf("%d/%d", sum1/m1,m/m1);
	}

	getchar();
	getchar();


}
int max(int a,int b){
	int ret;
	if(a>b) ret=a;
	else ret=b;
	return ret;
}
