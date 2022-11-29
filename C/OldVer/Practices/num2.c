#include <stdio.h>

void Print_Factorial ( const int N );

int main()
{
	int N;
	
	scanf("%d", &N);
	Print_Factorial(N);
	return 0;
}
void Print_Factorial ( const int N )
{
	if(N<0){
		printf("Invalid input");
		return;
	}
	
	int cnt=0,mul=1,carry=0,temp=0,digit=1;	//cnt-the digit calc  mul-the fraction process  carry-as the name  temp-save the temporary number
	int result[3000]={1,0};	//initialize the array

	for(;mul<=N;mul++){	//to calc
		for(cnt=0;cnt<digit;cnt++){
			temp=result[cnt]*mul+carry;
			result[cnt]=temp%10;
			carry=temp/10;
		}
		while(carry>=1){	//to solve the carry problem
			result[digit]=carry%10;
			carry/=10;
			digit++;
		}
		carry=0;
	}

	for(int b=digit-1;b>=0;b--){
		printf("%d", result[b]);
	}
}
