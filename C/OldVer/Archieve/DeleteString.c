#include <stdio.h>
#include <string.h>

int main(){
	char a[81];
	char b[81];
	gets(a);
	gets(b);
	int la,lb,lret,lmae;
	char *ret=a;
	
	while(1){
		if(strstr(ret,b)==NULL){
			break;
		}
		ret=strstr(a,b);
		lret=strlen(ret);
		la=strlen(a);
		lb=strlen(b);
		lmae=la-lret;
		a[lmae]='\0';
		ret+=lb;
		ret=strcat(a,ret);
	}
	printf("%s", ret);
	
	return 0;
}
