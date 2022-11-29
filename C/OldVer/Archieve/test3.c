#include <stdio.h>
int main(){
	int a, b;
	FILE *input = fopen("input.txt","r");
	if(input){
		fscanf(input, "%d %d", &a, &b);
		FILE *out = fopen("out.txt","w");
		fprintf(out,"%d",a+b);
		fclose(out);
		fclose(input);
	}else{
		printf("Error!!!");
	}
	
}


