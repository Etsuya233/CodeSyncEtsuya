#include <cstdio>
#include <cmath>

typedef struct Point{
	double x, y;
	int used = 0;
} point;

int n;
double ans = 0x7fffffff;
point arr[16];

int main(){
	point zero = {.x = 0, .y = 0};
	arr[0] = zero;
	scanf("%d", &n);
	for(int i = 1; i <= n; i++){
		scanf("%lf%lf", &arr[i].x, &arr[i].y);
	}
	printf("%.2f", ans);
}

double getDistance(point a, point b){
	return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}

