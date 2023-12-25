#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

typedef struct PointOnGraph{
	int x, y;
} point;

int n;
point arr[2000010];

double dist(int a, int b);
double merge(int l, int r);
double findmindist(int l, int r);
bool cmpPoint(point a, point b);

int main(){
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf("%d %d", &arr[i].x, &arr[i].y);
	}
	sort(arr, arr + n, cmpPoint);
	printf("%.4lf", merge(0, n - 1));
	return 0;
}

double dist(int a, int b){
	return sqrt(1.0 * (arr[a].x - arr[b].x) * (arr[a].x - arr[b].x) + 1.0 * (arr[a].y - arr[b].y) * (arr[a].y - arr[b].y));
}

double merge(int l, int r){
	double ret = 0x7fffffff;
	if(l == r) return ret;
	if(r - l == 1) return dist(l, r);
	int mid = (l + r) / 2;
	double lans = merge(l, mid), rans = merge(mid + 1, r);
	double mindist = min(lans, rans);
	int lb = mid, rb = mid + 1;
	for(; lb > l && arr[mid].x - arr[lb].x <= mindist; lb--);//find the correct boundary
	for(; rb < r && arr[rb].x - arr[mid].x <= mindist; rb++);
	double mindist2 = findmindist(lb, rb);
	return min(mindist, mindist2);
}

double findmindist(int l, int r){
	double ret = 0x7fffffff;
	for(int i = l ; i < r; i++){
		for(int j = i + 1; j <= r; j++){
			ret = min(ret, dist(i, j));
		}
	}
	return ret;
}

bool cmpPoint(point a, point b){
	if(a.x < b.x) return true;
	else if(a.x == b.x){
		if(a.y <= b.y) return true;
		return false;
	} else {
		return false;
	}
}
