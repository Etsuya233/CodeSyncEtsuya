#include <cstdio>

long long n, m, sum = 0;
long long res[1005] = {0, 1, 1};

void func(long long step);
long long func_2(long long step);

int main(){
	scanf("%lld%lld", &m, &n);
	//	func(m);
	//	printf("%lld", sum);
	printf("%lld", func_2(n - m + 1));
	return 0;
}

void func(long long step){
	if(step > n) return;
	if(step == n){
		sum += 1;
		return;
	}
	func(step + 1);
	func(step + 2);
}

long long func_2(long long step){
	if(step == 1) return 1;
	if(step == 2) return 1;
	if(step < 1) return 0;
	long long a = res[step - 1]? res[step - 1]: res[step - 1] = func_2(step - 1);
	long long b = res[step - 2]? res[step - 2]: res[step - 2] = func_2(step - 2);
	return a + b;
}
