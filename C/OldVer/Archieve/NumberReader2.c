#include <stdio.h>
int cut(int num1){
	int ret;
	ret=num1%10000;
	num1/=10000;
	return ret;
}
int anti(int num2){
	int antinum;
	for(;num2>0;num2/=10){
		antinum=antinum*10+num2%10;
	}
	return antinum;
}
void read(int needread){
	int reada;
	int digit=0;
	for(;reada>0;){
		reada=needread%10;
		needread/=10;
		printf("%d",reada);
		if(reada==0){
			while(1){
				needread/=10;
				reada=needread%10;
				digit++;
			}
			printf("%d", reada);
		}
//		while(reada==0){
//			needread/=10;
//			reada=needread%10;
//			digit++;
//		}
		switch(digit){
		case 0:
			printf(" qian ");
			break;
		case 1:
			printf(" bai ");
			break;
		case 2:
			printf(" shi ");
			break;
		}
		digit++;
	}
}

int main(){
	int num,y=0,w=0,g=0;
	scanf("%d",&num);
//	g=num&10000;
//	num/=10000;
//	w=num&10000;
//	num/=10000;
//	y=num%10000;	Functionize
	g=cut(num);
	w=cut(num);
	y=cut(num);
	read(g);
	read(w);
	read(y);
	

	return 0;
}
