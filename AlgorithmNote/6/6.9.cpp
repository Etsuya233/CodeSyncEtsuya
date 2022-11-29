#include <cstdio>
#include <algorithm>
using namespace std;

int main(){
	int n;
	scanf("%d", &n);
	int arr[n];
	for(int i = 1; i <= n; i++) arr[i - 1] = i;
	do{
		for(int i = 0; i < n; i++) printf("%5d", arr[i]);
		printf("\n");
	} while(next_permutation(arr, arr + n));
	return 0;
}
