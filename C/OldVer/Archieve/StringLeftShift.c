#include <stdio.h>
#include <string.h>
int main(void){
	char a[101]="";
	char left[101]="";
	char right[101]="";
	int digit;
	gets(a);
	scanf("%d",&digit);
	digit=(strlen(a)+digit)%strlen(a);	//Prevent the situation that the N is bigger than strlen(a)
	
	int cnt;
	int len=strlen(a)-digit;
	for(cnt=0;cnt<digit;cnt++){
		left[cnt]=a[cnt];
	}
	for(cnt=0;cnt<len;cnt++){
		right[cnt]=a[cnt+digit];
	}
	char *ret=strcat(right,left);

	printf("%s", ret);
}
