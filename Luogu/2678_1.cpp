#include <cstdio>

int main(){
	int l, n, m;
	scanf("%d%d%d", &l, &n, &m);
	int arr[n + 2];
	arr[0] = 0;
	arr[n + 1] = l;
	for(int i = 1; i <= n; i++){
		scanf("%d", &arr[i]);
	}
	
	int head = 1, foot = l + 1, half, sum;
	while(head < foot){
		sum = 0;
		half = (head + foot) / 2;
		for(int i = 0; i <= n; i++){
			if(arr[i + 1] - arr[n] < half) sum++;
		}
		if(sum > m) foot = half;
		else head = half + 1;
	}
	
	printf("%d", head - 1);
}
