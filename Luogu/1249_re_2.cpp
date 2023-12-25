#include <iostream>
using namespace std;

int n;
int num[10001] = {0};

int digit = 1;
int res[10000] = {1};

void multiply(int a);

int main(){
	cin >> n;
	int limit = 0;
	int sum = 0;
	for(int i = 2; sum < n; i++){
		num[i] = 1;
		limit = i;
		sum += i;
	}
	int more = sum - n;
	if(more == 1){
		num[2] = 0;
		num[limit] = 0;
		num[limit + 1] = 1;
	} else {
		num[more] = 0;
	}
	for(int i = 2; i <= limit + 1; i++){
		if(num[i]){
			multiply(i);
			cout << i << " ";
		}
	}
	cout << "\n";
	for(int i = digit - 1; i >= 0; i--){
		cout << res[i];
	}
	return 0;
}

void multiply(int a){
	for(int i = 0; i < digit; i++){
		res[i] *= a;
	}
	int carry = 0;
	for(int i = 0; i < digit; i++){
		res[i] += carry;
		carry = res[i] / 10;
		res[i] %= 10;
	}
	while(carry > 0){
		res[digit++] = carry % 10;
		carry /= 10;
	}
}
