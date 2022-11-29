#include <stdio.h>
void read(int a);
int main() {
	int a = 1;
	while (a != '\n') {
		a = getchar();
		read(a);
		if (a!='\n') printf(" ");
	}
	printf("\b");
	return 0;
}
void read(int a) {
	char py[][10] = {"ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"};
	if (a == '-') {
		printf("fu");
	} else if (a == '\n') {

	} else {
		printf("%s", py[a - 48]);
	}
}
