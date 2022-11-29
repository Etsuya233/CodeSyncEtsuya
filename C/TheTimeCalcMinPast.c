#include <stdio.h>
int main()
{
	printf("请输入当前时间（1130表示11点30分）：\n");
	int t1, h1,m1, m, h2, m2, h, t;
	scanf("%d %d", &t1, &m);
	h1 = t1 / 100;
	m1 = t1 % 100;
	h = m / 60;
	m = m % 60;
	m2 = m1 + m;
	h2 = h1 + h;
	if (m2 > 60){
		h2++;
		m2 = m2 - 60;
	}
	t = h2*100 + m2;
	printf("%d", t);
	
	return 0;
}
