#include <cstdio>
#include <cmath>

typedef struct Point{
	double x, y;
	int used = 0;
} point;

int n;
double ans = 0x7fffffff;
point arr[16];

double getDistance(point a, point b);
void dfs(int now, double dis, int step);

int main(){
	point zero = {.x = 0, .y = 0};
	arr[0] = zero;
	scanf("%d", &n);
	for(int i = 1; i <= n; i++){
		scanf("%lf%lf", &arr[i].x, &arr[i].y);
	}
	dfs(0, 0, 0);
	printf("%.2f", ans);
}

double getDistance(point a, point b){
	return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}

void dfs(int now, double dis, int step){
	if(step == n){
		ans = (dis < ans)? dis: ans;
		printf("%.2f\n", ans);
		return;
	}
	double minDis = 0x7fffffff;
	int minPos[16];
	int amount = 0;
	for(int j = 1; j <= n; j++){
		if(j == now || arr[j].used) continue;
		double thisDis = getDistance(arr[now], arr[j]);
		if(thisDis < minDis){
			minDis = thisDis;
			minPos[amount = 0] = j;
		} else if(thisDis == minDis){
			minDis = thisDis;
			minPos[++ amount] = j;
		}
	}
	for(int i = 0; i < amount + 1; i++){
		arr[minPos[i]].used = 1;
		dfs(minPos[i], dis += minDis, step + 1);
		arr[minPos[i]].used = 0;
	}
}
