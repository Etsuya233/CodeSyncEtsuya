#include <stdio.h>
int main(){
	int min=0,n,u,d,r=0;
	scanf("%d %d %d",&n,&u,&d);
	while(r<n){
		if(min%2==0){
			min++;
			r+=u;
		}else{
			min++;
			r-=d;
		}
	}
	printf("%d",min);
	
	return 0;
}
