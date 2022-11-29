#include <stdio.h>

int main()
{
double h1, h2, m1, m2, t1, t2, t, t60;
int t60h;

printf("请分别输入几时几分与后来的几时几分，每个数字中间用空格隔开：");
scanf("%lf %lf %lf %lf", &h1, &m1, &h2, &m2);
t1 = h1 + m1/60;
t2 = h2 + m2/60;
t = t2 - t1;
t60 = 60 * t;
t60h = t60;
printf("\n时间差为：%d时%d分。", t60h/60, t60h%60);

return 0;   
}

