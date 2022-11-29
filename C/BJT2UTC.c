#include <stdio.h>
int main(){
	int t, h, m;
	printf("请输入时间（BJT）：\n");
	scanf("%d", &t);
	if ( t < 0 ){
		printf("时间格式错误！\n程序终止！");
	} else if ( t > 2359 ){
		printf("时间格式错误！\n程序终止！");
	} else {
		printf("你输入的时间（BJT）为 %d\n", t);
		h = t / 100;
		m = t % 100;
		h -= 8;
		if (h >= 0){
			h = h;
		} else {
			h += 24;
		}
		printf("该时间的世界协调时（UTC）为：%d\n", h*100 + m);
	}
	
	return 0;
}
