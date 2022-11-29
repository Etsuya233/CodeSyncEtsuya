#include <cstdio>
#include <iostream>
using namespace std;

int binarySearch(int arr[], int search, int length);

int main(){
	int n;
	cin >> n;
	int arr[n];
//	int search;
//	cin >> search;
	for(int i = 0; i < n; i++){
		cin >> arr[i];
		arr[i] = 1 - arr[i] % 2;
	}
	cout << binarySearch(arr, 1, n);
}

int binarySearch(int arr[], int search, int length){
	int head = 0, foot = length, half;
	while(head < foot){
		half = (head + foot) / 2;
		if(arr[half] >= search){
			foot = half;
		} else {
			head = half + 1;
		}
	}
	if(arr[foot] == search) return foot;
	else return -1;
}
