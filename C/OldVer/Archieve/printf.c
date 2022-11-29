#include <stdio.h>
int main()
{
    int a, b = 24, c = 36, d = 48, e =3, f = 72;\
    a = b += c ++ -d + --e/-f;
    printf("%d %d", a, b); 

    return 0;
}