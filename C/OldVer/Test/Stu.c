#include<stdio.h>
void write();
void read();
int main(int argc, char **argv){
	printf("\tWelcome to Library System.\nPlease input r or w to continue:\n");
	char next = '0';
	scanf("%c", &next);
	if(next=='w'){
		write();
	}else if(next=='r'){
		read();
	}else{
		printf("Error!");
	}
	return 0;
}
void write(){
	FILE *data = fopen("StuData.txt","w");
	int amount;
	printf("How many students you need to enrol?\n");
	scanf("%d",&amount);
	fprintf( data,"%d\n", amount);
	int cnt=0;
	struct stu{
		char name[20];
		char author[20];
		int rate;
	};
	struct stu St[amount];
	for(cnt=0;cnt<amount;cnt++){
		printf("\tNow input Book %d's name:\n",cnt+1);
		scanf("%19s", &St[cnt].name);
//		fgets(St[cnt].name,19,stdin);
		fprintf(data,"%s\n",St[cnt].name);
		printf("\tNow input Book %d's author:\n",cnt+1);
		scanf("%19s", &St[cnt].author);
//		fgets(St[cnt].author,19,stdin);
		fprintf(data,"%s\n",St[cnt].author);
		printf("\tNow input Book %d's rate:\n",cnt+1);
		scanf("%d", &St[cnt].rate);
		fprintf(data,"%d\n",St[cnt].rate);
	}
}
void read(){
	
}
