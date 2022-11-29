#include <stdio.h>
int main(){
	int n,an=0,dig=0,a,b,c=0;
	scanf("%d",&n);
	if(n < 0){
		printf("fu ");
		n = -n;
	}
	a=n;
	b=n;
	while(a>0){
		a/=10;
		dig++;
	}
//	printf("%d", dig);
//	The next step is to get the "anti" number.
	while(b>0){
		an=an*10+b%10;
		b/=10;
	}
//	printf("%d", an);
//	The next problem is to solve the zero question
	while(an>0){
		c=0;
		c=an%10;
		switch(c){
		case 1:
			printf("yi ");
			break;
		case 2:
			printf("er ");
			break;
		case 3:
			printf("san ");
			break;
		case 4:
			printf("si ");
			break;
		case 5:
			printf("wu ");
			break;
		case 6:
			printf("liu ");
			break;
		case 7:
			printf("qi ");
			break;
		case 8:
			printf("ba ");
			break;
		case 9:
			printf("jiu ");
			break;
		case 0:
			printf("ling ");
			break;
		}
		an/=10;
		dig--;
	}
	for(;dig>0;dig--){
		printf("ling ");
	}
	return 0;
}
