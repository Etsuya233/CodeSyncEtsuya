#include <cstdio>
#include <cmath>

long long res[21][21][21] = {0};
long long func(long long a, long long b, long long c);

int main(){
	long long a, b, c;
	scanf("%lld%lld%lld", &a, &b, &c);
	do{
		if(a == b && b == c && b == -1) break;
		printf("w(%lld, %lld, %lld) = %lld\n", a, b, c, func(a, b, c));
		scanf("%lld%lld%lld", &a, &b, &c);
	} while(true);
	return 0;
}

long long func(long long a, long long b, long long c){
	if(a <= 0 || b <= 0 || c <= 0) return 1;
	if(a > 20 || b > 20 || c > 20) return func(20, 20, 20);
//	if(a == b & b == c) return pow(2, a);
	if(a < b && b < c){
		long long i = (res[a][b][c - 1])? res[a][b][c - 1]: res[a][b][c - 1] = func(a, b, c - 1);
		long long j = (res[a][b - 1][c - 1])? res[a][b - 1][c - 1]: res[a][b - 1][c - 1] = func(a, b - 1, c - 1);
		long long k = (res[a][b - 1][c])? res[a][b - 1][c]: res[a][b - 1][c] = func(a, b - 1, c);
		return i + j - k;
	} else {
		long long i = (res[a - 1][b][c])? res[a - 1][b][c]: res[a - 1][b][c] = func(a - 1, b, c);
		long long j = (res[a - 1][b - 1][c])? res[a - 1][b - 1][c]: res[a - 1][b - 1][c] = func(a - 1, b - 1, c);
		long long k = (res[a - 1][b][c - 1])? res[a - 1][b][c - 1]: res[a - 1][b][c - 1] = func(a - 1, b, c - 1);
		long long l = (res[a - 1][b - 1][c - 1])? res[a - 1][b - 1][c - 1]: res[a - 1][b - 1][c - 1] = func(a - 1, b - 1, c - 1);
		return i + j + k - l;
	}
}
