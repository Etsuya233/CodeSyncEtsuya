#include <stdio.h>
#include <math.h>

int main(){
	int num, sqr=0, dig, diga, digb, nums;
	scanf("%d", &dig);
	diga = pow ( 10, dig-1);
	digb = pow ( 10, dig ) -1;
	for(num = diga; num <= digb; num++){
		nums = num;
		while(nums > 0){
			sqr += pow ((nums%10), dig);
			nums /= 10;
		}
		if(num == sqr){
			printf("%d\n", sqr);
		}
		sqr = 0;
	}
	
	
	return 0;
}
