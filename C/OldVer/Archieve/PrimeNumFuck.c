#include <stdio.h>
int main(){
	int a, b, num, is =0, nump, cnt=0, sum=0;
	scanf("%d %d", &a, &b);
	for(num = a;num <= b;num++){
		for(nump = 2;nump<num; nump++){
			is = 0;
			if(num%nump==0){
				is = 1;
				
				break;
			}
		}
		if(is == 0){
		cnt ++;
		sum += num;
		}
	}
	printf("%d %d", cnt, sum);
	return 0;
}
