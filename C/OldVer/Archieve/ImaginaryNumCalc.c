#include <stdio.h>
void calc(double,double,double,double,int *p);
int main(void){
	double a1,b1,a2,b2;
	scanf("%lf %lf %lf %lf", &a1,&b1,&a2,&b2);
	for(int a=0;a<4;a++){
		if(b1>=0.0){
			printf("(%.1f+%.1fi) ",a1,b1);
		}else{
			printf("(%.1f%.1fi) ",a1,b1);
		}
		switch(a){
		case 0:
			printf("+ ");
			break;
		case 1:
			printf("- ");
			break;
		case 2:
			printf("* ");
			break;
		case 3:
			printf("/ ");
			break;
		}
		if(b2>=0.0){
			printf("(%.1f+%.1fi) =",a2,b2);
		}else{
			printf("(%.1f%.1fi) =",a2,b2);
		}
		calc(a1,b1,a2,b2,&a);
	}
}
void calc(double a1,double b1,double a2,double b2,int *p){
	double a,b; 
	switch(*p){
	case 0:
		a=a1+a2;
		b=b1+b2;
		break;
	case 1:
		a=a1-a2;
		b=b1-b2;
		break;
	case 2:
		a=a1*a2-b1*b2;
		b=a1*b2+a2*b1;
		break;
	case 3:
		a=(a1*a2+b1*b2)/(a2*a2+b2*b2);
		b=(-a1*b2+a2*b1)/(a2*a2+b2*b2);
		break;
	}
	if((a<=0.05&&a>=-0.05)&&(b<=0.05&&b>=-0.05)){
		printf(" 0.0");
	}else if((a>=0.05||a<=-0.05)&&(b<=0.05&&b>=-0.05)){
		printf(" %.1f",a);
	}else if((a<=0.05&&a>=-0.05)&&(b>=0.05||b<=-0.05)){
		printf(" %.1fi",b);
	}else{
		if(b>0.0){
			printf(" %.1f+%.1fi",a,b);
		}else{
			printf(" %.1f%.1fi",a,b);
		}
	}
	if(*p!=3){
		printf("\n");
	}
}
