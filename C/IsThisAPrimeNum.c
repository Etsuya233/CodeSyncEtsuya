#include <stdio.h>

int main(){
	int num, count=0, nump=1;
	scanf("%d", &num);
	for(;num>= nump;nump++){
		if(num%nump==0){
			count++;
		}
	}
	if(count<=2){
		printf("%d is a 素数.", num);	
	} else {
		printf("%d is a 质数.",num);
	}
	return 0;	
}
