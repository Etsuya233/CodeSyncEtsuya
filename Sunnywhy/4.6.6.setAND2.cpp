#include <cstdio>

int main(){
	int n, m;
	scanf("%d%d", &n, &m);
	int arr1[n], arr2[m];
	for(int i = 0; i < n; i++) scanf("%d", &arr1[i]);
	for(int i = 0; i < m; i++) scanf("%d", &arr2[i]);
	
	int p1 = 0, p2 = 0, result[10001] = {-1}, cnt = 0;
	while(p1 < n && p2 < m){
		if(arr1[p1] == arr2[p2]){
			result[cnt++] = arr1[p1];
			p1++; p2++;
		} else if(arr1[p1] > arr2[p2]){
			result[cnt++] = arr2[p2];
			p2++;
		} else if(arr1[p1] < arr2[p2]){
			result[cnt++] = arr1[p1];
			p1++;
		}
	}
	while(p1 < n) for(; p1 < n;) result[cnt++] = arr1[p1++];
	while(p2 < m) for(; p2 < m;) result[cnt++] = arr2[p2++];
	
	for(int i = 0; i < cnt; i++){
		printf("%d", result[i]);
		if(i != cnt - 1) printf(" ");
	}
}
