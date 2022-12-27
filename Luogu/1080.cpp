#include <cstdio>

typedef struct person{
	int l, r;
} Person;

int main(){
	long long l = 1, min;
	int n;
	scanf("%d", &n);
	Person arr[n + 1];
	for(int i = 0; i <= n; i++){
		scanf("%d%d", &arr[i].l, &arr[i].r);
		l *= arr[i].l;
	}	
	min = l;
	for(int i = 1; i < n; i++){
		long long ret = l / arr[i].l / arr[i].r;
		min = (ret < min)? ret: min;
	}
	printf("%lld", min);
	return 0;
}
