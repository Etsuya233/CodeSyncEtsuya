#include <cstdio>

int main(){
	int l, n, m;
	scanf("%d%d%d", &l, &n, &m);
	int arr[n + 2];
	for(int i = 1; i <= n; i++) scanf("%d", &arr[i]);
	arr[0] = 0;
	arr[n + 1] = l;
	int head = 0, foot = l + 1, half = 0;
	while(head < foot){
		int sum = 0;
		half = (head + foot) / 2;
		int now = 0;
		int next = 0;
		for(int i = 0; i < n + 1; i++){
			next++;
			if(arr[next] - arr[now] < half){
				sum ++;
			} else {
				now ++;
			}
		}
		if(sum <= half){
			head = half + 1;
		} else {
			foot = half;
		}
	}
	printf("%d", head - 1);
	
	
	return 0;
}
