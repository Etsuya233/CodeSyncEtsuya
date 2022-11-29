#include <cstdio>
#include <iostream>
using namespace std;

void quickSort(int arr[], int head, int foot);

int main(){
	int n;
	cin >> n;
	int arr[n];
	for(int i = 0; i < n; i++) cin >> arr[i];
	quickSort(arr, 0, n - 1);
	for(int i = 0; i < n; i++) cout << arr[i];
}

void quickSort(int arr[], int head, int foot){
	int temp = arr[head	];
	int l = head, r = foot;
	while(l < r){
		while(l < r && arr[r] > temp){
			r--;
		}
		arr[l] = arr[r];
		while(l < r && arr[l] <= temp){
			l++;
		}
		arr[r] = arr[l];
	}
	arr[l] = temp;
	
	if(head == foot){
		return;
	} else {
		quickSort(arr, head, l - 1);
		quickSort(arr, l + 1, foot);
	}
}
