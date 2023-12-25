#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

int x[2000005], y[200005];
int n;
double res = 1e10;

double dist(int a, int b);

int main(){
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf("%d %d", &x[i], &y[i]);
	}
	for(int i = 0; i < n; i++){
		for(int j = i + 1; j < n; j++){
			double temp = dist(i, j);
			res = min(res, temp);
		}
	}
	printf("%.4f", res);
	return 0;
}

double dist(int a, int b){
	return sqrt(((x[a] - x[b]) * (x[a] - x[b]) + (y[a] - y[b]) * (y[a] - y[b])) * 1.0);
}
