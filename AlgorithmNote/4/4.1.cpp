#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

int main(){
	int n;
	cin >> n;
	int arr[n] = {0};
	int maxIndex = 0;
	for(int i = 0; i < n; i++){
		scanf("%d", &arr[i]);
		if(arr[maxIndex] < arr[i]) maxIndex = i;
	}
	int max = arr[maxIndex];
	for(int i = maxIndex; i < n - 1; i++){
		arr[i] = arr[i+1];
	}
	sort(arr, &arr[n - 1]);
	printf("%d\n", max);
	for(int i = 0; i < n - 1; i++){
		printf("%d", arr[i]);
		if(i != n - 2) printf(" ");
	}
}

