#include <iostream>
#include <cmath>
using namespace std;

int main(){
	double m, g, r, a1, a2;
	cin >> m >> g >> r >> a1 >> a2;
	double res = m * g * r / (a2 - a1) - m * r * a2 / (a2 - a1);
	cout << res;
	
	
}
