#include <cstdio>
#include <algorithm>
using namespace std;

typedef struct apple{
	int height, power;
} Apple;

bool cmpPower(Apple a, Apple b);

int main(){
	int n, s, a, b, sum = 0;
	scanf("%d%d%d%d", &n, &s, &a, &b);
	Apple arr[n];
	for(int i = 0; i < n; i++){
		scanf("%d%d", &arr[i].height, &arr[i].power);
	}
	sort(arr, arr + n, cmpPower);
	for(int i = 0; i < n; i++){
		if(s < 0) break;
		if((s -= arr[i].power) >= 0 && arr[i].height <= a + b){
			sum++;
			continue;
		} else {
			s += arr[i].power;
		}
	}
	printf("%d", sum);
	return 0;
}

bool cmpPower(Apple a, Apple b){
	if(a.power < b.power) return true;
	return false;
}
