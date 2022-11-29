#include <stdio.h>
int main(){
	int num[100];
	int a=0,cnt=0,times=0;
	while(a!=-1){
		scanf("%d",&a);
		num[cnt]=a;
		cnt++;
	}
	
	int b=0;
	for(b=0;b<10;b++){
		times=0;
		for(a=0;a<cnt;a++){
			if(num[a]==b){
				times++;
			}
		}
		printf("%d have appeared %d times.\n",b,times);
	}
	
	return 0;
}
