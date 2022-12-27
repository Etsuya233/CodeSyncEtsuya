#include <cstdio>

int main(){
	int l, n, k;
	scanf("%d%d%d", &l, &n, &k);
	int arr[n];
	for(int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	
	int head = 0, foot = l + 1, sum, half;
	while(head < foot){
		sum = 0;
		double fakeHalf = 1.0 * (head + foot) / 2;
		half = (fakeHalf > (int)fakeHalf)? ((int)fakeHalf + 1): fakeHalf;
		for(int i = 1; i < n; i++){
			int j = 1;
			while(true){
				int res = (arr[i] - arr[i - 1]) / j;
				if((arr[i] - arr[i - 1]) % j) res ++;
				if(res <= half) break;
				j ++;
				sum ++;
			}
		}
		if(sum > k) head = half;
		else foot = half - 1;
	}
	printf("%d", head + 1);
}
