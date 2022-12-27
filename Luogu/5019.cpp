#include <cstdio>

int main(){
	int n;
	scanf("%d", &n);
	int arr[n + 1];
	arr[n] = 0;
	for(int i = 0; i < n; i++) scanf("%d", &arr[i]);
	int flag = 1;	//To memory whether we have filled one of the road
	long long sum = 0;
	
	int starter = 0, ender = n;
	while(flag){
		flag = 0;
		for(int i = starter; i < n; i++){
			if(!arr[i]) starter ++;
			else break;
		}
		int filled = 0;
		for(int i = starter; i <= n; i++){
			if(arr[i]){
				filled = 1;
				flag = 1;
				arr[i] --;
			} else if(!arr[i] && filled){
				sum++;
				filled = 0;
			}
		}
	}
	printf("%lld", sum);
	return 0;
}
