#include <iostream> 
#include <algorithm>
#include <cmath>
using namespace std;

int main(){
	int w, m, n;
	cin >> w >> m >> n;
	int x1, y1, x2, y2;
	y1 = (m - 1) / w;
	y2 = (n - 1) / w;
	if(y1 % 2 == 0){
		x1 = (m - 1) % w + 1;
	} else {
		x1 = w - (m - 1) % w;
	}
	if(y2 % 2 == 0){
		x2 = (n - 1) % w + 1;
	} else {
		x2 = w - (n - 1) % w;
	}
	cout << abs(x2 - x1) + abs(y2 - y1) << "\n";
	return 0;
}
