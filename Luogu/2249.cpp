#include <cstdio>
#include <algorithm>
using namespace std;

int main(){
	int n, a;
	scanf("%d%d", &n, &a);
	int arr[n];
	int answer[a];
	for(int i = 0; i < n; i++) scanf("%d", &arr[i]);
	for(int i = 0; i < a; i++){
		int b;
		scanf("%d", &b);
		int loc = lower_bound(arr, arr + n, b) - arr;
		if(arr[loc] == b) answer[i] = loc + 1;
		else answer[i] = -1;
	}
	for(int i = 0; i < a; i++){
		printf("%d ", answer[i]);
	}
	return 0;
}
