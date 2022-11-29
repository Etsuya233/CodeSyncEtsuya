#include <cstdio>
#include <cmath>

double f(double x);

int main(){
	int a;
	const double EPSILON = 0.001;	//Precision < 0.01
	scanf("%d", &a);
	
	double l = -5.0, r = 5.0; //To calculate the interval of the result
	double mid;
	while(r - l > EPSILON){
		mid = 1.0 * (l + r) / 2;
		if(f(mid) > a){
			r = mid;
		} else if(f(mid) < a) {
			l = mid;
		} else {
			break;
		}
	}
	printf("%.2f", mid);
}

double f(double x){
	return x * x * x + x * x + x;
}
