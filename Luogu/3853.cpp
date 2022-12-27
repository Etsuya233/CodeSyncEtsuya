#include <cstdio>

int main(){
	int l, n, k;
	scanf("%d%d%d", &l, &n, &k);
	int arr[n];
	for(int i = 0; i < n; i++){
		scanf("%d", &arr[i]);
	}
	int head = 0, foot = l + 1, half;
	while(head < foot){
		if(n == 2){
			head = l / (k + 1);
			if(l % 2 == 0) head --;
			break;
		}
		half = (head + foot) / 2 + 1;
		int sum = 0;
		for(int i = 1; i < n; i++){
			if(arr[i] - arr[i - 1] > half) sum++;
		}
		if(sum <= k){
			foot = half - 1;
		} else {
			head = half;
		}
	}
	printf("%d", head + 1);
}
