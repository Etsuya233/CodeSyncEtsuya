#include <stdio.h>
int main(){
	int a=2,b=1,c,N,cnt=0,iint,poi;
	double result=0.0;
	scanf("%d", &N);
	while(cnt < N){
		result+=1.0*a/b;
		c=a+b;
		b=a;
		a=c;
		cnt++;
	}
	iint = result;
	poi = 100*result - iint*100;
	printf("%d.%d", iint, poi);
	return 0;
}
