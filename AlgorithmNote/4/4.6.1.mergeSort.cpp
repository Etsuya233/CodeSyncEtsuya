#include <cstdio>
//merge sort

void mergeSort(int arr[], int l, int r);
void merge(int arr[], int l1, int r1, int l2, int r2);

int main(){
	int n;
	scanf("%d", &n);
	int arr[n];
	for(int i = 0; i < n; i++) scanf("%d", &arr[i]);
	
	mergeSort(arr, 0, n - 1);
	for(int i = 0; i < n; i++){
		printf("%d", arr[i]);
		if(i != n-1) printf(" ");
	}
}

void mergeSort(int arr[], int l, int r){
	int half = (l + r) / 2;
	if(l < r) {
		mergeSort(arr, l, half);
		mergeSort(arr, half + 1, r);
		merge(arr, l, half, half + 1, r);
	}
}

void merge(int arr[], int l1, int r1, int l2, int r2){
	int start = l1, foot = r2 - l1 + 1;
	int ret[foot], loc = 0;
	while(l1 <= r1 && l2 <= r2){
		if(arr[l1] < arr[l2]){
			ret[loc++] = arr[l1++];
		} else {
			ret[loc++] = arr[l2++];
		}
	}
	while(l1 <= r1) for(; l1 <= r1;) ret[loc++] = arr[l1++];
	while(l2 <= r2) for(; l2 <= r2;) ret[loc++] = arr[l2++];
	
	for(int i = 0; i < foot;){
		arr[start++] = ret[i++];
	}
}
