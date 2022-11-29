#include<stdio.h>
int main()
{
    int cm;
    scanf("%d", &cm);
    int foot = cm / 30.48;
    int inch = (cm / 30.48 - foot)*12;
    printf("\n%d cm 为 %d 尺 %d寸", cm, foot, inch);

    return 0;

}