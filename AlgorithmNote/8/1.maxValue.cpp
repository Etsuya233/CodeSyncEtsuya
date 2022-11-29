#include <cstdio>

typedef struct item{
	int value;
	int weight;
} Item;

typedef struct test{
	int location = -1, n, sumV, sumW;
} Test;

int maxValue = 0;
Item arr[21];
int w, n;
Test data[1000];

void shoping(int n, int sumV, int sumW);

int main(){
	scanf("%d%d", &w, &n);
	for(int i = 0; i < n; i++){
		scanf("%d%d", &arr[i].value, &arr[i].weight);
	}
	shoping(n - 1, 0, 0);
	printf("%d", maxValue);
	for(int i = 0; data[i].location != -1; i++){
		printf("%d\t%d\t%d\t%d\n", data[i].location, data[i].n, data[i].sumV, data[i].sumW);
	}
	return 0;
}

//int i = 0;

void shoping(int n, int sumV, int sumW){
	if(n == -1){
		maxValue = (sumV > maxValue)? sumV: maxValue;
//		data[i].location = 0;
//		data[i].n = n;
//		data[i].sumV = sumV;
//		data[i].sumW = sumW;
//		i++;
	} else {
		shoping(n - 1, sumV, sumW);
		sumV += arr[n].value;
		sumW += arr[n].weight;
		if(sumW > w){
			sumV -= arr[n].value;
			sumW -= arr[n].weight;
			maxValue = (sumV > maxValue)? sumV: maxValue;
//			data[i].location = 1;
//			data[i].n = n;
//			data[i].sumV = sumV;
//			data[i].sumW = sumW;
//			i++;
		} else {
			shoping(n - 1, sumV, sumW);
		}
	}
}
