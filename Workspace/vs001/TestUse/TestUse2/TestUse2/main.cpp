#include <cstdio>
#include <iostream>
using namespace std;

void mergeSort(int arr[], int head, int foot);

int main() {
	int arr[100];
	for (int i = 0; i < 8; i++) {
		cin >> arr[i];
	}
	mergeSort(arr, 0, 8);
	for (int i = 0; i < 8; i++) cout << arr[i] << " ";


}

void mergeSort(int arr[], int head, int foot) {
	if (foot - head <= 1) {
		if (arr[head] > arr[foot]) {
			int temp = arr[head];
			arr[head] = arr[foot];
			arr[foot] = temp;
		}
	}

	int half = (head + foot) / 2;
	mergeSort(arr, head, half);
	mergeSort(arr, half + 1, foot);

	int i = head, j = half + 1, loc = 0;
	int storage[foot - half + 1] = { 0 };
	while (i <= half || j <= foot) {
		if (i == half + 1 && j < foot) {
			for (; j <= foot; j++) {
				storage[loc++] = arr[j];
			}
		}
		else if (j == foot + 1 && i <= half) {
			for (; i <= half; i++) {
				storage[loc++] = arr[i];
			}
		}
		else if (j == foot + 1 && i == half + 1) {
			break;
		}

		if (storage[i] < storage[j]) {
			storage[loc++] = arr[j++];
		}
		else {
			storage[loc++] = arr[i++];
		}
	}

	int k = head;
	for (int i = 0; i < foot - half + 1; i++, k++) {
		arr[k] = storage[i];
	}

}