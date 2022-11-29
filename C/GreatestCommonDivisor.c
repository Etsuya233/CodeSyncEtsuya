#include <stdio.h>
int main(){
	printf("欢迎来到最大公约数计算器。\n请键入两位数：\n");
	int x, y, a;
	scanf("%d %d", &x, &y);
	if ( x > y ){
		a = y;
	} else if ( x < y ){
		a = x;
	} else {
		a = x;
	}
	for( ; a>0; a--){
		if( x % a == 0 && y % a == 0){
			break;
		}
	}
	printf("%d 与 %d 的最大公约数为 %d。\n", x, y, a);
	
	return 0;
}
