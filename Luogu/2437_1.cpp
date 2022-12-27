#include <cstdio>

int res[1005][221] = {0};
int m, n, step = 3, targetStep, digit = 1, carry = 0;

void fibonacci();

int main(){
	res[1][0] = 1;
	res[2][0] = 2;
	scanf("%d%d", &m, &n);
	targetStep = n - m;
	for(int i = 3; step <= targetStep; i++){
		fibonacci();
	}
	for(int i = digit - 1; i >= 0; i--){
		printf("%d", res[targetStep][i]);
	}
	return 0;
}

void fibonacci(){
	for(int i = 0; i < digit; i++){
		int number = res[step - 1][i] + res[step - 2][i] + carry;
		res[step][i] = number % 10;
		carry = number / 10;
	}
	if(carry > 0){
		res[step][digit++] = carry;
		carry = 0;
	}
	step++;
}
