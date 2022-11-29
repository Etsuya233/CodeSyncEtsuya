#include <cstdio>

int arr[5003][5003] = {0};
int length = 1;

void plus(int row);

int main(){
	arr[0][0] = 1;
	arr[1][0] = 2;
	int n;
	scanf("%d", &n);
	if(n <= 2){
		printf("%d", n);
	} else {
		for(int i = 3; i <= n; i++){
			plus(i);
		}
		for(int i = length - 1; i >= 0; i--){
			printf("%d", arr[n - 1][i]);
		}
	}
	return 0;
}

void plus(int row){
	row--;
	int carry = 0;
	int i = 0;
	for( ; i < length; i++){
		int number = carry + arr[row - 1][i] + arr[row - 2][i];
		arr[row][i] = number % 10;
		carry = number / 10;
	}
	if(carry != 0){
		length++;
		arr[row][i] = carry;
	}
}
