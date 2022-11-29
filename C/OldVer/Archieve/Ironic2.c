#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main(void){
	char str[500001]="",temp[500001]="",ret[500001]="";
//	gets(str);
	gets(str);
	
	int cnt=0,a=0,len=strlen(str);
	for(a=0;a<=len+1;a++){
		if((str[a]!=' ')&&(a<len)){
			temp[cnt]=str[a];
			temp[cnt+1]='\0';
			cnt++;
//			printf("%s\n", temp);
		}else{
			if(cnt!=0){
				if(strlen(ret)!=0){
					strcat(temp," ");
					strcat(temp,ret);
					strcpy(ret,temp);
				}else{
					strcpy(ret,temp);
				}
				strcpy(temp,"");
				cnt=0;
			}
		}
	}
	printf("%s\n", ret);
	
	
}
