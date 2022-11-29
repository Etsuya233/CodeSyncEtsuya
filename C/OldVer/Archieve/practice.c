#include <stdio.h>
int main(){
	int a;
	scanf("%d", &a);
	int d = a;
	//int b = a + 1, c = b + 1, d = c + 1;
	int b, c;
	int big = a + 3;
	for (; a < big; a ++){
		b=d;
		for(; b < big; b++){
			c=d;
			for(;c <= big; c ++){
				printf("%d%d%d\n", a, b, c);
			}
		}
	}
//	while (a <= big){
//		b =a;
//		while(b<= big){
//			c=a;
//			while(c<=big){
//				if (a!=b){
//					if(b!=c){
//						if(a!=c){
//							printf("%d%d%d\n",a ,b, c);
//						}
//					}
//				}
//				c++;
//			}
//			b++;
//		}
//		a++;
//	}
	
	return 0;
}
