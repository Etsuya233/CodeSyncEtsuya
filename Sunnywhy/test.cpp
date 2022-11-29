#include <cstdio>

int main(){
	int n;
	scanf("%d", &n);
	int data[n];
	for(int i = 0; i < n; i++) scanf("%d", &data[i]);
	
	//algorithm
	int head = 0, foot = n - 1, half;
	while(head < foot){
		half = (head + foot) / 2;
		if(data[half] > data[foot]) head = half + 1;
		else if(data[half] == data[foot]) foot--;
		else foot = half;
	}
	printf("%d", data[head]);
}
