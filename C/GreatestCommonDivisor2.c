#include <stdio.h>
int main(){
	printf("欢迎来到最大公约数计算器。\n请键入两位数：\n");
	int x, y, a, b, c, d;
	//scanf("%d %d", &x, &y);
	c = y;
	d = x;
	
	//辗转相除法
	while( y != 0 ){
		b = x % y;
		x = y;
		y = b;
	}
	a = x;
	
	printf("%d 与 %d 的最大公约数为 %d。\n", d, c, a);
	
	getchar();
	getchar();
	return 0;
}
