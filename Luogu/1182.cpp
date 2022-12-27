#include <cstdio>
#include <cmath>

int n, m;
int arr[100005], special[100005] = {0};
int sum, add, head, foot, half;

int judge(int loc);

int main(){
	scanf("%d%d", &n, &m);
	for(int i = 0; i < n; i++){
		scanf("%d", &arr[i]);
	}
	for(int i = 1; i < n - 1; i++){
		if(arr[i - 1] > arr[i] && arr[i + 1] > arr[i]) special[i] = 1;
		if(arr[i - 1] < arr[i] && arr[i + 1] < arr[i]) special[i] = 1;
	}
	
	add = arr[0], head = 1, foot = 50;
	while(head < foot){
		sum = 0, add = arr[0];
		half = (int)ceil(1.0 * (head + foot) / 2);
		for(int i = 1; i < n; i++){
			if(special[i - 1]){
				if(add == arr[i - 1]) judge(i);
				else {
					sum ++;
					add = arr[i];
					if(add > half) add = 0;
				}
			} else {
				judge(i);
			}
		}
		sum ++;
		if(sum > m) head = half;
		if(sum <= m) foot = half - 1;
	}
	printf("%d", head);
}

int judge(int loc){
	if(arr[loc] + add == half){
		sum ++;
		add = 0;
		return 1;
	} else if(arr[loc] + add < half){
		add += arr[loc];
		return 0;
	} else {
		sum ++;
		add = arr[loc];
		return -1;
	}
}
