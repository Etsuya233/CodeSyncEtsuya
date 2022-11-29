#include <stdio.h>

int main(){
	int a = 1, x;
	int num[1];
	scanf("%d", &x);
	for(int i = 0; ; i++){
		num[i] = x;
		printf("%d ", num[i]);
		a++;
		scanf("%d", &x);
		if(x == -1) break;
	}
	
	
}
