#include <stdio.h>
int main(){
	int x, even = 0, odd = 0;
	scanf("%d", &x);
	while(x != -1){
		if(x % 2 == 0){
			even ++;
		} else {
			odd ++;
		}
		scanf("%d", &x);
	}
	printf("\nOdd Number: %d, Even Number: %d.", odd, even);
	return 0;
}
