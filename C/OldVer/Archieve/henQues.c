#include <stdio.h>
int main(){
	int n,y,f,flag=0;
	scanf("%d", &n);
	for(f=0;f<100;f++){
		y=0;
		for(y=0;y<50;y++){
			if(98*f-199*y==n){
				printf("%d.%d", y,f);
				flag =1;
				break;
			}
		}
	}
	if(flag!=1){
		printf("No Solution");
	}
	return 0;
}
