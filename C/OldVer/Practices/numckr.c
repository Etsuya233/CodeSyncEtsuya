#include <stdio.h>

void Print_Factorial ( const int N );

int main()
{
	int N;
	
	scanf("%d", &N);
	Print_Factorial(N);
	return 0;
}

void Print_Factorial ( const int N ){
	if(N>=0 && N<=1000){
		int ret[3000] = {1, 0};
		int digit = 1, mul = 1, carry = 0;
		if( N == 0 ){
			printf("1");
		}else{
			for(;mul<=N;mul++){
				for(int cnt=0;cnt<=digit-1;cnt++){
					int temp=ret[cnt]*mul;
					ret[cnt]=(mul*ret[cnt]+carry)%10;
					carry=(temp+carry)/10;
					
				}
				if(carry!=0 && ret[digit]==0){
					ret[digit]=carry;
					carry=0;
					digit++;
				}
				for(int a=0;a<=digit-1;a++){
					printf("%d\t");
				}
				printf("\n");
			}
		}
		if(N!=0){
			for(int cnt=digit-1;cnt>=0;cnt--){
				printf("%d", ret[cnt]);
			}
		}
	} else {
		printf("Invalid input");
	}
}
