#include <cstdio>

int main(){
	long long rect = 0, square = 0;
	long long x, y;
	scanf("%lld%lld", &x, &y);
	// Rect + Square
	rect = x * (x + 1) / 2 * y * (y + 1) / 2;
	long long i = x, j = y;
	for(; i >= 1 && j >= 1; i--, j--){
		square += i * j;
	}
	rect -= square;
	printf("%lld %lld", square, rect);
	return 0;
}
