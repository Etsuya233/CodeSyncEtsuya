#include <cstdio>
//过 on
int main(){
	int arr[50005] = {0}, pre[50005] = {0};
	int result[8] = {-1, -1, -1, -1, -1, -1, -1, -1}, cnt = 0;
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; i++){
		int num;
		scanf("%d", &num);
		arr[i] = num;
		pre[i] = pre[i - 1] + num;
		pre[i] %= 7;
	}
	for(int i = 0; i <= n && cnt < 7; i++){    //Get array result
		if(result[pre[i]] == -1){
			result[pre[i]] = i;
			cnt++;
		}
	}
	int max = 0;
	for(int i = 1; i <= n; i++){
		if(i > result[pre[i]] && result[pre[i]] >= 0){
			if(i - result[pre[i]] > max) max = i - result[pre[i]];
		}
	}
	printf("%d", max);
}