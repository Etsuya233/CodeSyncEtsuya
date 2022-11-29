#include <stdio.h>
int main(){
	//To generate an array in number order
	int N,a=1;
	scanf("%d",&N);
	int se[N];
	for(;a<=N;a++){
		se[a-1]=a;
	}
	
	//To calc
	a=0;
	int cnt=1,flag=N-1;
	while(flag>0){
		if(a==N-1){
			a-=N-1;
		}else{
			a++;
		}
		if(se[a]!=0){
			cnt++;
			if(cnt==3){
				se[a]=0;
				cnt=0;
				flag--;
			}
		}
		printf("  a=%d\tcnt=%d\tse0=%d\tse1=%d\tse2=%d\tse3=%d\tse4=%d\tse5=%d\n",a,cnt,se[0],se[1],se[2],se[3],se[4],se[5]);
	}
	
	//Travelsal
	for(a=0;a<N;a++){
		if(se[a]!=0){
			printf("%d", a+1);
			break;
		}
	}
	
	
	return 0;
}
