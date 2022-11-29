#include <stdio.h>

int main(){
	int num, nump, is;	//is=1 reprezent a prime
	for (num=2; num<=100; num++){
		//nump=2;
		//is=1;
		for(nump=2;nump<num;nump++){
			if(num%nump==0){
				is=0;
				break;
			}
		}
		if(is==1){
			printf("%d ", num);
		}
	}
	
	return 0;	
}
