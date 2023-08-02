#include <stdio.h>
#include <stdlib.h>

void swapArray(int* a, int* b);
void traverseArray(int arr[], int length);
void bubbleSort(int arr[], int length);
void selectionSort(int arr[], int length);
void insertionSort(int arr[], int length);

int main() {
	int arr[] = { 55,22,44,21,53,23,56,28 };
	int lengthOfArr = 8;

	//Testpoint 0
	{
		bubbleSort(arr, 6);
		selectionSort(arr, 8);
		insertionSort(arr, 8);
		traverseArray(arr, 8);
	}
	
	//Test point 1
	{

	}
	return 0;
}

void bubbleSort(int arr[], int length) {
	for (int i = 0; i < length; i++) {
		for (int j = 0; j < length - i - 1; j++) {
			if (arr[j] > arr[j + 1]) swapArray(&arr[j], &arr[j + 1]);
			else continue;
		}
	}
}

void selectionSort(int arr[], int length) {
	int minIndex;
	for (int i = 0; i < length - 1; i++) {
		minIndex = i;
		for (int j = i + 1; j < length; j++) {
			if (arr[j] < arr[minIndex]) minIndex = j;
		}
		swapArray(&arr[minIndex], &arr[i]);
	}
}

void swapArray(int* a, int* b) {
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

void traverseArray(int arr[], int length) {
	for (int i = 0; i < length; i++) {
		printf("%d\t", arr[i]);
	}
}

void insertionSort(int arr[], int length) {
	for (int i = 0; i < length; i++) {
		for (int j = i; j > 0; j--) {
			if (arr[j] < arr[j - 1]) swapArray(&arr[j], &arr[j - 1]);
		}
	}
}

