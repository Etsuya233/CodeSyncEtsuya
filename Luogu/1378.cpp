#include <iostream>
#include <algorithm>
#include <cmath>

//啊啊啊？这就过了？？？

#define PI 3.14159267

using namespace std;

int n;
double maximum = 0.0;
int x, y, xx, yy;
int p[10][2] = {0};
int walked[10] = {0};
double circle[10] = {0};

double biggestS(int no);
void dfs(int no, double now);

int main(){
	cin >> n;
	cin >> x >> y >> xx >> yy;
	for(int i = 0; i < n; i++){
		cin >> p[i][0] >> p[i][1];
	}
	if(x > xx) swap(x, xx);
	if(y > yy) swap(y, yy);
	dfs(0, 0);
	double ans = 1.0 * (xx - x) * (yy - y) - maximum;
	cout << (int)(ans + 0.5);
}

void dfs(int no, double now){
	if(no >= n) if(now > maximum) maximum = now;
	for(int i = 0; i < n; i++){
		if(!walked[i]){
			walked[i] = 1;
			dfs(no + 1, biggestS(i) + now);
			walked[i] = 0;
		}
	}
}

double biggestS(int no){
	double rm = 10000;
	rm = min(1.0 * (p[no][0] - x), rm);
	rm = min(1.0 * (xx - p[no][0]), rm);
	rm = min(1.0 * (p[no][1] - y), rm);
	rm = min(1.0 * (yy - p[no][1]), rm);
	for(int i = 0; i < n; i++){
		if(walked[i] && i != no){
			double dis = sqrt(1.0 * (p[no][0] - p[i][0]) * (p[no][0] - p[i][0]) + (p[no][1] - p[i][1]) * (p[no][1] - p[i][1]));
			dis -= circle[i];
			if(dis > 0) rm = min(dis, rm);
			else rm = 0;
		}
	}
	circle[no] = rm;
	return PI * rm * rm;
}

