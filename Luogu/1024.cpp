#include <cstdio>
#include <cmath>

int main(){
	double a, b, c, d, answer[3];
	int amount = 0;
	scanf("%lf%lf%lf%lf", &a, &b, &c, &d);
	for(double i = -100.00; (int)i <= 100 && amount < 3; i += 0.01){
		double ret = pow(i, 3) * a + pow(i, 2) * b + pow(i, 1) * c + d;
		if(fabs(ret) < 0.01){
			answer[amount++] = ret;
			i += 0.99;
		}
	}
	for(int i = 0; i < 3; i++){
		printf("%.2f ", answer[i]);
	}
}
