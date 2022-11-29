#include <stdio.h>

int main() {
	struct map {
		int isA;
		int isB;
	};

	struct map** maptest = (struct map**)malloc(sizeof(struct map*) * 10);
	for (int cnt = 0; cnt < 10; cnt++) {
		maptest[cnt] = (struct map*)malloc(sizeof(struct map) * 10);
	}
	


}