#include <stdio.h>
int main(){
	int x, antix = 0, tln;
	scanf("%d", &x);
	do {
		tln = x % 10;
		x /= 10;
		antix = antix *  10 + tln; 
	} while (x != 0);
	printf("%d", antix);
	return 0;
}
