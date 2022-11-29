#include <stdio.h>
int main(){
	int a,b;
	scanf("%d/%d", &a,&b);
	
	//Get the biggest num
	int max;
	if(a>b){
		max=a;
	}else{
		max=b;
	}
	
	//Get the GCD
	for(;max>0;max--){
		if(a%max==0 && b%max==0){
			break;
		}
	}
	
	//Print
	printf("%d/%d", a/max,b/max);
	
	
	return 0;
}
