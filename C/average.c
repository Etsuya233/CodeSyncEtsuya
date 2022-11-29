#include <stdio.h>
int main(){
	int sum = 0, ave, times = 0, x = 0;
	while ( x >= 0){
		scanf("%d", &x);
		if (x >= 0){
			sum += x;
			times ++;
		}
	}
	ave = sum / times;
	printf("The average is %d.", ave);
	return 0;
}
