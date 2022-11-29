#include<stdio.h>
int main(){
	int n, a;
	double sum=0;
	scanf("%d", &n);
	for (a=1; a<=n; a++){
		sum = sum + 1.0/a;
	}
	printf("%lf", sum);
}
