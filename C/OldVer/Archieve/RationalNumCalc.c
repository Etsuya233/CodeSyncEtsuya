#include<stdio.h>
int max(long long int,long long int);
int main(void){
	long long int amount;
	scanf("%lld", &amount);
	//Get the Least Common Multiple
	int cnt;
	long long int a,b;
	long long int a1,b1;
	long long int m;
	for(cnt=0;cnt<amount;cnt++){
		scanf("%lld/%lld",&a1,&b1);
		if(cnt==0){
			a=a1,b=b1;
		}else{
			for(m=b;(m%b!=0)||(m%b1!=0);m++);
			a=m/b*a+m/b1*a1;
			b=m;
			int c=max(a,b);
			for(;(a%c!=0)||(b%c!=0);c--);
			a/=c;
			b/=c;
//			printf("%d/%d\n",a,b);
		}
	}

	//Get the average
	b*=amount;
//	printf("%d\n",b);
	//Get the GCD
	int c;
	c=max(a,b);
	for(;(a%c!=0)||(b%c!=0);c--);
	if(b/c==1){
		printf("%d",a/c);
	}else{
		printf("%d/%d",a/c,b/c);
	}
	
}
int max(long long int a,long long int b){
	int ret;
	if(a>b){
		ret=a;
	}else{
		ret=b;
	}
	return ret;
}
