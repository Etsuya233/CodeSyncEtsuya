#include <stdio.h>
int main(){
	int x=1,y=1,n,flag=0;
	scanf("%d",&n);
	for(;x<n;x++){
		for(y=x;y<n;y++){
			if(x*x+y*y==n){
				printf("%d %d\n",x,y);
				flag=1;
			}
		}
	}
	if(flag==0){
		printf("No Solution");
	}
	return 0;
}
