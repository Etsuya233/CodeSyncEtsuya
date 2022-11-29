#include <cstdio>
#include <iostream>
using namespace std;

void binarySearchInterval(int arr[], int search, int length);
int lower_bound(int A[], int left, int right, int x);

int main(){
	int n;
	cin >> n;
	int arr[n];
	for(int i = 0; i < n; i++) cin >> arr[i];
	int search;
	cin >> search;
	binarySearchInterval(arr, search, n);
//	cout << lower_bound(arr, 0, n, search);
}

int binarySearch(int arr[], int search, int length){
	int head = 0, foot = length - 1;
	while(head <= foot){
		int half = (head + foot) / 2;
		if(arr[half] == search){
			return half;
		} else if(arr[half] > search){
			foot = half - 1;
		} else {
			head = half + 1;
		}
	}
	return -1;
}

//void binarySearchInterval(int arr[], int search, int length){
//	int head = 0, foot = length - 1, setHead, setFoot, half;
//	int flag = 0;	//To detect the number whether the number has been found.
//	while(head <= foot){
//		half = (head + foot) / 2;
//		if(arr[half] == search){
//			flag = 1;
//			break;
//		} else if(arr[half] > search){
//			foot = half - 1;
//		} else {
//			head = half + 1;
//		}
//	}
//	if(flag){
//		setHead = setFoot = half;
//		while(setHead >= 0){
//			if(arr[--setHead] != search) break;
//		}
//		while(setFoot <= length){
//			if(arr[++setFoot] != search) break;
//		}
//		setHead ++;
//	} else {
//		if(half == length - 1) half ++;
//		setFoot = setHead = half;
//	}
//	printf("[%d,%d)", setHead, setFoot);
//}

void binarySearchInterval(int arr[], int search, int length){
	int head = 0, foot = length, half, setLeft, setRight;
	while(head < foot){
		half = (head + foot) / 2;
		if(arr[half] >= search){
			foot = half;
		} else {
			head = half + 1;
		}
	}
	setLeft = head;
	head = 0, foot = length;
	while(head < foot){
		half = (head + foot) / 2;
		if(arr[half] > search){
			foot = half;
		} else {
			head = half + 1;
		}
	}
	setRight = foot;
	printf("[%d,%d)", setLeft, setRight);
}

int lower_bound(int A[], int left, int right, int x){
//	int head = 0, foot = length - 1, half, setLeft, setRight;
//	while(head < foot){
//		half = (head + foot) / 2;
//		if(arr[half] >= search){
//			foot = half;
//		} else {
//			head = half + 1;
//		}
//	}
	int mid;
	while(left < right){
		mid = (left + right) / 2;
		if(A[mid] >= x){
			right = mid;
		} else {
			left = mid + 1;
		}
	}
	return left;
	
}
