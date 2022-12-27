#include <cstdio>
#include <cmath>

int n, m;
int arr[100005];
int sum, add, head, foot, half, dir = 0;

int judge(int loc);

int main(){
	scanf("%d%d", &n, &m);
	for(int i = 0; i < n; i++){
		scanf("%d", &arr[i]);
	}
	head = 1, foot = 0x7fffffff;
	while(head < foot){
		add = 0, sum = 1;
		half = (int)ceil(1.0 * (head + foot) / 2);
		for(int i = 0; i < n; i++){
			if(arr[i] > half){
				sum = 0x7fffffff;
				break;
			}
			if(add + arr[i] > half){
				add = 0;
				sum ++;
			}
			add += arr[i];
		}
		if(sum > m) head = half;
		if(sum <= m) foot = half - 1;
	}
	printf("%d", head + 1);
	return 0;
}

