#include <cstdio>
#include <cstdlib>

void quickSort(int arr[], int head, int foot);

int main(){
	int n;
	scanf("%d", &n);
	int arr[n];
	for(int i = 0; i < n; i++) scanf("%d", &arr[i]);
	
	quickSort(arr, 0, n - 1);
	
	for(int i = 0; i < n; i++){
		printf("%d", arr[i]);
		if(i != n - 1) printf(" ");
	}
	
	return 0;
}

void quickSort(int arr[], int head, int foot){
	if(head < foot){
		int temp = arr[head];
		int l = head, r = foot;
		while(l < r){
			while(l < r && arr[r] > temp) r--;
			arr[l] = arr[r];
			while(l < r && arr[l] <= temp) l++;
			arr[r] = arr[l];
		}
		arr[l] = temp;
		
		quickSort(arr, head, l - 1);
		quickSort(arr, l + 1, foot);
	}
}
