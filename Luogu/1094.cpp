#include <cstdio>
#include <algorithm>
using namespace std;

int main(){
	int w, n;
	scanf("%d%d", &w, &n);
	int arr[n];
	for(int i = 0; i < n; i++) scanf("%d", &arr[i]);
	sort(arr, arr + n);
	int left = 0, right = n - 1, sum = 0;
	while(left <= right){
		if(left == right && arr[left] <= w){
			sum++;
			break;
		} else if(arr[left] + arr[right] <= w){
			left ++;
			right --;
			sum ++;
		} else if(arr[left] + arr[right] > w){
			if(arr[right] <= w)sum ++;
			right --;
		}
	}
	printf("%d", sum);
	return 0;
}
