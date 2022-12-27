#include <cstdio>

int main(){
	int n, x;
	scanf("%d%d", &n, &x);
	int arr[n];
	for(int i = 0; i < n; i++){
		scanf("%d", &arr[i]);
	}
	int sum = 0;
	for(int i = 1; i < n; i++){
		int add;
		if(add = arr[i] + arr[i - 1] > x){
			int dif = add - x;
			if(dif <= arr[i]){
				sum += dif;
				arr[i] -= dif;
			} else {
				sum += dif;
				arr[i - 1] -= dif - arr[i];
				arr[i] = 0;
			}
		}
	}
	printf("%d", sum);
	return 0;
}
