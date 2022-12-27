#include <cstdio>
#include <algorithm>
using namespace std;

int main(){
	int n;
	scanf("%d", &n);
	int arr[n];
	for(int i = 0; i < n; i++) scanf("%d", &arr[i]);
	sort(arr, arr + n);
	int min = 0x7fffffff;
	for(int i = 0; i < n;){
		int ret = 1;
		for(int j = i + 1; j < n; j++){
			if(arr[j] == arr[j - 1] + 1) ret++;
			else break;
		}
		min = (ret < min)? ret: min;
		i += ret;
	}
	printf("%d", min);
	return 0;
}
