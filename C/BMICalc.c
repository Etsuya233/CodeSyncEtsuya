#include <stdio.h>

int main()
{
    double height;
    double weight;
    double bmi;
    double bmi1;

    printf("欢迎来到BMI计算器！\n请在这里依次输入你的升高（米），体重（千克），中间用空格隔开：");
    scanf("%lf %lf", &height, &weight);
    printf("你的BMI为：%f", (weight/height/height));
    return 0;


}