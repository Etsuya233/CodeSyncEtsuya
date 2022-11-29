#include<stdio.h>
int main()
{
	printf("请输入一个小于157的十进制数：\n");
	
	int bin;
	scanf("%d", &bin);
	printf("该数的十六进制为：%d", ( bin / 16 * 10 + bin % 16));
	
	
	return 0;
}
