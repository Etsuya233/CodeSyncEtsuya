#include <stdio.h>
int main(){
	int N,K;
	scanf("%d %d", &N, &K);
	int se[N];
	int cnt=0;
	
	//Input all the number into an array: se
	int a;
	while(cnt<N){
		scanf("%d", &a);
		se[cnt]=a;
		cnt++;
	}
//	printf("%d", se[3]);
	
	//start the calc
	int digit=1,times=1,reserve;
	while(times<=K){
		while(digit<=N-1){
			if(se[digit-1]>se[digit]){
				reserve=se[digit-1];
				se[digit-1]=se[digit];
				se[digit]=reserve;
			}
			digit++;
		}
		digit=1;
		times++;
	}
	
	//travelsal the array: se
	for(a=0;a<N;a++){
		printf("%d", se[a]);
		if(a!=N-1){
			printf(" ");
		}
	}
	
	return 0;
}
