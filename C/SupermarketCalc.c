#include <stdio.h>
int main(){
	int bill, input;
	printf("请输入商品总额：\n");
	scanf("%d", &bill);
	printf("请输入金额：\n");
	scanf("%d", &input);
	
	if (bill - input <= 0){
		printf("找零%d元", input - bill);
	}
	if (bill - input > 0){
		printf("输入金额不足，无法完成付款！");
	}
	
	return 0;
	}
