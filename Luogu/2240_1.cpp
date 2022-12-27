// Maybe it successd by accident!

#include <cstdio>
#include <algorithm>
using namespace std;

int main(){
	int n, k, longest = 0;
	scanf("%d%d", &n, &k);
	int arr[n];
	for(int i = 0; i < n; i++){
		scanf("%d", &arr[i]);
		longest = max(longest, arr[i]);
	}
	sort(arr, arr + n);
	int head = 0, foot = longest + 1, half;
	while(head < foot){
		long long sum = 0;
		half = (head + foot) / 2;
		if(half == 0) {
			head = 1;
			break;
		}
		for(int i = 0; i < n; i++){
			sum += arr[i] / half;
		}
		if(sum >= k) head = half + 1;
		if(sum < k) foot = half;
	}
	printf("%d", head - 1);
}
