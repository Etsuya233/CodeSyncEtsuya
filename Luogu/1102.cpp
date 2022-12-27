#include <cstdio>
#include <algorithm>
using namespace std;

int main(){
	int n, c;
	long long sum = 0;
	scanf("%d%d", &n, &c);
	int arr[n];
	for(int i = 0; i < n; i++) scanf("%d", &arr[i]);
	for(int i = 1; i < n; i++){
		for(int j = 0; j < i; j++){
			if(arr[i] - arr[j] > c) continue;
			else if(arr[i] - arr[j] == c) sum++;
			else break;
		}
	}
	printf("%lld", sum);
	return 0;
}
