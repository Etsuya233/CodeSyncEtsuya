#include <cstdio>
#include <iostream>
using namespace std;

void merge(int arrA[], int arrB[], int arrC[], int n1, int n2);
void merge3(int arr[], int arrC[], int n1, int f1, int n2, int f2);
void mergeSort(int arr[], int head, int foot);
int* merge2(int arrA[], int arrB[], int n1, int n2);
int minimun(int a, int b);
void mergeSort2(int arr[], int length);

int main(){
	int n;
	cin >> n;
	int arrA[n];
	for(int i = 0; i < n; i++) cin >> arrA[i];
	//	cin >> m;
	//	int arrB[m];
	//	for(int i = 0; i < m; i++) cin >> arrB[i];
	
	mergeSort(arrA, 0, n - 1);
//	mergeSort2(arrA, n - 1);
	for(int i = 0; i < n; i++) cout << arrA[i] << " ";
	
	
}

void merge(int arrA[], int arrB[], int arrC[], int n1, int n2){
	int p1 = 0, p2 = 0, loc = 0;
	while(p1 < n1 && p2 < n2){
		if(arrA[p1] > arrB[p2]){
			arrC[loc++] = arrB[p2++];
		} else {
			arrC[loc++] = arrA[p1++];
		}
	}
	while(p1 < n1) for(; p1 < n1; p1++) arrC[loc++] = arrA[p1++];
	while(p2 < n2) for(; p2 < n2; p2++) arrC[loc++] = arrB[p2++];
}

void merge3(int arr[], int arrC[], int n1, int f1, int n2, int f2){
	int p1 = n1, p2 = n2, loc = 0;
	while(p1 <= f1 && p2 <= f2){
		if(arr[p1] > arr[p2]){
			arrC[loc++] = arr[p2++];
		} else {
			arrC[loc++] = arr[p1++];
		}
	}
	while(p1 <= f1) for(; p1 <= f1; ) arrC[loc++] = arr[p1++];
	while(p2 <= f2) for(; p2 <= f2; ) arrC[loc++] = arr[p2++];
}

void mergeSort(int arr[], int head, int foot){
	if(foot - head <= 1){
		if(arr[head] > arr[foot]){
			int temp = arr[head];
			arr[head] = arr[foot];
			arr[foot] = temp;
		}
		return;
	}
	
	int half = (head + foot) / 2;
	mergeSort(arr, head, half);
	mergeSort(arr, half + 1, foot);
	
	int storage[foot - head + 1];
	merge3(arr, storage, head, half, half + 1, foot);
	for(int i = head; i <= foot; i++) arr[i] = storage[i - head];
	
}

int* merge2(int arrA[], int arrB[], int n1, int n2){
	int p1 = 0, p2 = 0, loc = 0;
	int *ret = (int*)malloc(sizeof(int) * (n1 + n2));
	while(p1 < n1 && p2 < n2){
		if(arrA[p1] > arrB[p2]){
			ret[loc++] = arrB[p2++];
		} else {
			ret[loc++] = arrA[p1++];
		}
	}
	while(p1 < n1) for(; p1 < n1; p1++) ret[loc++] = arrA[p1++];
	while(p2 < n2) for(; p2 < n2; p2++) ret[loc++] = arrB[p2++];
	return ret;
}

void mergeSort2(int arr[], int length){
	for(int step = 2; step / 2 <= length; step *= 2){
		for(int i = 0; i < length; i += step){
			int half = i + step / 2 - 1;
			if(half + 1 < length){
				int storage[step];
				merge3(arr, storage, i, half, half + 1, minimun(length - 1, i + step - 1));
				for(int j = 0; i < minimun(length - 1, i + step - 1); i++){
					arr[j] = storage[j - i]; 
				}
			}
		}
	}
}

int minimun(int a, int b){
	return (a > b)? b: a;
}
