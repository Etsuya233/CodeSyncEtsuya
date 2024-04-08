#include <iostream>
#include <set>
using namespace std;

typedef struct Point {
	int x1, x2, y1, y2, e = 1; 
	friend bool operator < (Point a, Point b){
		if (a.x1 != b.x1) {
            return a.x1 < b.x1;
        }
        if (a.x2 != b.x2) {
            return a.x2 < b.x2;
        }
        if (a.y1 != b.y1) {
            return a.y1 < b.y1;
        }
        if (a.y2 != b.y2) 
			return a.y2 < b.y2;
		return a.e < b.e;
	}; 
} po;

typedef struct Line {
	int a, b;
	friend bool operator < (Line a, Line b){
		if(a.a != b.a) return a.a < b.a;
		return a.b < b.b;
	};
} li;

int n;
li templi;
set<li> liset;
li arr[1005];
int ans = 1;

po getPoint(li l1, li l2);
int gcd(int a, int b);

int main(){
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> templi.a >> templi.b;
		liset.insert(templi);
	}
	//anti repeat line
	n = 0;
	for(auto it = liset.begin(); it != liset.end(); it++){
		arr[n + 1].a = (*it).a;
		arr[n + 1].b = (*it).b;
		n++;
	}
	ans += n;
	//anti repeat point
	for(int i = 2; i <= n; i++){
		set<po> poset;
		for(int j = 1; j <= i - 1; j++){
			po now = getPoint(arr[i], arr[j]);
			if(now.e == 0) continue;
			poset.insert(now);
		}
		ans += poset.size();
	}
	cout << ans << "\n";
	return 0;
} 

po getPoint(li l1, li l2){
	po ret;
	if(l1.a - l2.a == 0){
		ret.e = 0;
		return ret;
	}
	int px1 = l2.b - l1.b;
	int px2 = l1.a - l2.a;
	int py1 = l1.a * l2.b - l2.a * l1.b;
	int py2 = l1.a - l2.a;
	int xgcd = gcd(px1, px2);
	int ygcd = gcd(py1, py2);
	px1 /= xgcd;
	px2 /= xgcd;
	py1 /= ygcd;
	py2 /= ygcd;
	ret.x1 = px1;
	ret.x2 = px2;
	ret.y1 = py1;
	ret.y2 = py2;
	return ret;
}

int gcd(int a, int b){
	if(b == 0) return a;
	return gcd(b, a % b);
}
