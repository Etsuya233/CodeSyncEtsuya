#include <cstdio>
#include <algorithm>
using namespace std;

int main(){
	int n;
	scanf("%d", &n);
	long long arr[n];
	for(int i = 0; i < n; i++){
		scanf("%lld", &arr[i]);
	}
	sort(arr, arr + n);
	long long sum = 0, result = arr[0];
	for(int i = 1; i < n; i++){
		result += arr[i];
		sum += result;
	}
	printf("%lld", sum);
	return 0;
}
