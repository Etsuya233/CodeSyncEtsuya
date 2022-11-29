#include<stdio.h>
void read();
int main(int argc, char **argv){
	printf("\tWelcome to Library System.\nPlease input r or w to continue:\n");
	char next;
	scanf("%c", &next);
//	if(next=='r'){
//		
//	}else if(next=='w'){
//		
//	}else{
//		
//	}
	read();
	
	
	return 0;
}
void read(){
	FILE *data = fopen("StuData.txt","w");
	int amount;
	fprintf( data,"%d\n", amount);
	int cnt=0;
	struct stu{
		char name[20];
		char author[20];
		int rate;
	};
	struct stu St[amount];
	printf("How many students you need to enrol?\n");
	scanf("%d",&amount);
	for(cnt=0;cnt<amount;cnt++){
		scanf("%s", &St[cnt].name);
		fprintf(data,"%s\n",St[cnt].name);
		scanf("%s", &St[cnt].author);
		fprintf(data,"%s\n",St[cnt].name);
		scanf("%d", &St[cnt].rate);
		fprintf(data,"%d\n",St[cnt].rate);
	}
	
	
}
