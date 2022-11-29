#include <stdio.h>

void swapArray(int* a, int* b);
void traverseArray(int arr[], int length);
void selectionSort(int arr[], int length);

int main(){
	int arr[] = {55,22,44,21,53,23,56,28};
	selectionSort(arr, 8);
	traverseArray(arr, 8);
	
	
	
	return 0;
}

void selectionSort(int arr[], int length){
	int minIndex;
	for(int i = 0; i < length; i++){
//		max = arr[i];
		minIndex = i;
		for(int j = i + 1; j < length; j++){
			if(arr[j] < arr[minIndex]){
//				max = arr[j];
				minIndex = j;
			}
			swapArray(&arr[i], &arr[minIndex]);
		}
	}
}

void swapArray(int* a, int* b){
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

void traverseArray(int arr[], int length){
	for(int i = 0; i < length; i++){
		printf("%d\t", arr[i]);
	}
}
