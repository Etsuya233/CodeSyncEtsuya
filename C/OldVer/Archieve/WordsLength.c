#include <stdio.h>
int main(){
	char c='0';
	int cnt=0;
	while(1){
		scanf("%c", &c);
		if(c!=' '&&c!='.'){
			cnt++;
		}else if(c=='.'){
			printf("%d ",cnt);
			break;
		}else{
			printf("%d ",cnt);
			cnt=0;
		}
	}
	return 0;
}
