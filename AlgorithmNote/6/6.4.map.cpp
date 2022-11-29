#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;

int storage[21] = {0};
int data[20];
int sum = 0;
int n, k;
int shoulret = 0;

void deal(int start, int cnt);
int isPrime(int number);

int main(){
	scanf("%d%d", &n, &k);
	for(int i = 1; i <= n; i++){
		scanf("%d", &data[i]);
	}
	sort(data, data + n);
	deal(1, k);
	printf("%d", sum);
}

void deal(int start, int cnt){
	if(cnt == 0){
		int all = 0;
		for(int i = 1; i <= k; i++){
			all += storage[i];
		}
		if(isPrime(all)){
			sum++;
		}
		return;
	}
	for(int i = start; i <= n; i++){
		storage[cnt] = data[i];
		deal(i + 1, cnt - 1);
	}
}

int isPrime(int number){
	int flag = 1;
	if(number == 1) return 0;
	else {
		for(int i = 2; i <= (int)sqrt(number); i++){
			if(number % i == 0){
				flag = 0;
				break;
			}
		}
	}
	return flag;
}
