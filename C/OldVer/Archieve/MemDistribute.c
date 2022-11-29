#include <stdio.h>
#include <stdlib.h>

int main(){
	char *s = "fuck u";
	char s1[]="fuck u";
	char *s2 = "fuck u";
	printf("%p\n%p\n%p", s, s1, s2);
}
