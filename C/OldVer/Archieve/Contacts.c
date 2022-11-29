#include <stdio.h>
int main(void){

	int row;
	scanf("%d", &row);
	int name[row][11],birth[row][11],sex[row][2],tele[row][17],tele2[row][17];
	
	int shu;
	for(shu=0;shu<row;shu++){
		scanf("%s %s %s %s %s", name[shu],birth[shu],sex[shu],tele[shu],tele2[shu]);
	}
	
	int fre,cnt,num;
	scanf("%d", &fre);
	for(cnt=0;cnt<fre;cnt++){
		scanf("%d", &num);
		if(num<=row){
			printf("%s %s %s %s %s",name[num],tele[num],tele2[num],sex[num],birth[num]);
		}else{
			printf("Not Found");
		}
		if(cnt<fre-1){
			printf("\n");
		}
	}
	
	getchar();
}
