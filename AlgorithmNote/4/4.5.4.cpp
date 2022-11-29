#include <cstdio>

long long binaryPower(int a, int b);
long long binaryPowerNotRecursion(int a, int b);

int main(){
	int a, b;
	scanf("%d %d", &a, &b);
	//	printf("%lld", binaryPower(a, b));
	printf("%lld", binaryPowerNotRecursion(a, b));
}

long long binaryPower(int a, int b){
	if(b == 0) {
		return 1;
	} else if(b & 1){
		return a * binaryPower(a, b - 1);
	} else {
		long long ret = binaryPower(a, b / 2);
		return ret * ret;
	}
}

long long binaryPowerNotRecursion(int a, int b){
	long long ret = 1;
	while(b > 0) {
		if (b & 1) {
			ret *= a;
		}
		a *= a;
		b >>= 1;
	}
	return ret;
}




