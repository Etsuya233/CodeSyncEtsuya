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
	
	double centre;
	if(n % 2 == 0){
		int num1 = head + n / 2 - 1;
		int num2 = head + n / 2;
		if(num1 > n - 1) num1 -= n;
		if(num2 > n - 1) num2 -= n;
		centre = 1.0 * (data[num1] + data[num2]) / 2;
	} else {
		int num = head + n / 2;
		if(num > n - 1) num -= n;
		centre = data[num];
	}
	
	printf("%.1f", centre);
}
