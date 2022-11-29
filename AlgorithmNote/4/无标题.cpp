#include <cstdio>
#include <iostream>
using namespace std;

int binarySearch(int arr[], int search, int length);

int main(){
	int n;
	cin >> n;
	int search;
	cin >> search;
	int arr[n];
	for(int i = 0; i < n; i++) cin >> arr[i];
	cout << binarySearch(arr, search, n);
	
}

int binarySearch(int arr[], int search, int length){
	int head = 0, foot = length - 1;
	while(head <= foot){
		int half = (head + foot) / 2;
		if(arr[half] == search){
			return half;
		} else if(arr[half] > search){
			head = half + 1;
		} else {
			foot = half - 1;
		}
	}
	return -1;
}
