#include <cstdio>
#include <cstdlib>
using namespace std;

typedef long long ll;

int n;
ll arr[500050];
ll tempa[500050];
ll res = 0;

void mergeSort(int l, int r);
void merge(int l, int r);
void printArray(int l, int r);

int main(){
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf("%lld", &arr[i]);
	}
	mergeSort(0, n - 1);
	printf("%lld", res);
	return 0;
}

void mergeSort(int l, int r){
	if(l == r){
		return;
	}
	int mid = (l + r) / 2;
	mergeSort(l, mid);
	mergeSort(mid + 1, r);
	//calc res
	int j = mid + 1;
	for(int i = l; i <= mid && j <= r; ){
		if(arr[i] > arr[j]){
			res += (mid - i + 1);
			j++;
		} else {
			i++;
		}
	}
//	printArray(l, r);
//	printf("%d\n", res);
	merge(l, r);
}

void merge(int l, int r){
	int mid = (l + r) / 2;
	int i = l, j = mid + 1, now = 0;
	while(i <= mid && j <= r){
		while(i <= mid && j <= r && arr[i] < arr[j]){
			tempa[now++] = arr[i++];
		}
		while(i <= mid && j <= r && arr[j] <= arr[i]){
			tempa[now++] = arr[j++];
		}
	}
	while(i <= mid){
		tempa[now++] = arr[i++];
	}
	while(j <= r){
		tempa[now++] = arr[j++];
	}
	for(i = 0; i < (r - l + 1); i++){
		arr[l + i] = tempa[i];
	}
}

void printArray(int l, int r){
	for(int i = l; i <= r; i++){
		printf("%lld ", arr[i]);
	}
	printf("\n");
}
