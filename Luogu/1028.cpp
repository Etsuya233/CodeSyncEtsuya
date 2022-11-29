#include <cstdio>

int res[1003] = {0};
int func(int n);

int main(){
	int n;
	scanf("%d", &n);
	printf("%d", func(n));
	return 0;
}

int func(int n){
	if(res[n]) return res[n];
	int half = n / 2;
	int ret = 1;
	for(int i = 1; i <= half; i++){
		ret += func(i);
	}
	return res[n] = ret;
}
