#include <stdio.h>
int main(){
	int cnt=0;
	char a;
	do{
		scanf("%c", &a);
		if(a!='.'){
			if(a!=' '){
				cnt++;
			}else{
				if(cnt!=0){
					printf("%d ",cnt);
					cnt=0;
				}
			}
		}else{
			break;
		}
	}while(1);
	if(cnt!=0){
		printf("%d",cnt);
	}
	
	return 0;
}
