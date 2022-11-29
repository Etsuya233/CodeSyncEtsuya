#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

int maxOfArray(int arr[], int arrayLength, int max, int index);

int main(){
	int n;
	cin >> n;
	int arr[n];
	for(int i = 0; i < n; i++){
		cin >> arr[i];
	}
	cout << maxOfArray(arr, n, arr[0], 0);
	
}

int maxOfArray(int arr[], int arrayLength, int max, int index){
	if(arr[index] > max) max = arr[index];
	if(index == arrayLength - 1) return max;
	else return maxOfArray(arr, arrayLength, max, index + 1);
}
