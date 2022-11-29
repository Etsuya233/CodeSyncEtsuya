#include <stdio.h>
int main()
{
    int h1, m1;
    scanf("%d %d", &h1, &m1);
    int t1 = (h1 + m1/60.0)*60;
    printf("%d", t1);
    return 0;
}