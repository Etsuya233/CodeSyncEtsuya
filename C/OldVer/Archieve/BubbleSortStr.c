#include <stdio.h>
#include <string.h>
int main(void){
	// Input N,K,Words
	int N,K;
	scanf("%d %d", &N,&K);
	char a[N][11];
	for(int z=0;z<N;z++){
		scanf("%s", &a[z]);
	}
//	for(int z=0;z<N;z++){
//		printf("%s\n", a[z]);
//	}

	//To calc		
	int times;
	char temp[11];
	for(;K>0;K--){
		for(times=1;times<N;times++){
//			printf("Compare: %s %s", a[tim])
			if(strcmp(a[times-1],a[times])>0){
				strcpy(temp,a[times-1]);
				strcpy(a[times-1],a[times]);
				strcpy(a[times],temp);
			}
		}
		
	}
	
	//Travelsal
	for(int z=0;z<N;z++){
		printf("%s", a[z]);
		if(z!=N-1){
			printf("\n");
		}
	}
	
	
	
}
