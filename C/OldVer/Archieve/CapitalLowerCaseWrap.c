#include <stdio.h>
int main(){
	char a='0';
	while(a!='#'){
		scanf("%c",&a);
		if(a>64&&a<91){
			a+=32;
		}else if(a>96&&a<123){
			a-=32;
		}
		printf("%c",a);
	}
	
	return 0;
}
