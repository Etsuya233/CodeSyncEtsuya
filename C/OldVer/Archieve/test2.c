#include <stdio.h>
int main(){
	
	FILE *printerName = fopen("fileName","mode");
	if (printerName){
		fscanf(printerName,"lanina");
		fclose(printerName);
	}else{
		
	}
	
}


