#include <iostream>
using namespace std;

int n, start;
double base;
double arr[70];
double pi =  3.14159265358979323846;

int main(){
	cin >> n >> start >> base;
	for(int i = start; i < start + n; i++){
		cin >> arr[i];
		arr[i] -= base;
	}
	for(int i = start + 4; i < start + n; i++){
		double k1 = i - 4, t1 = arr[i - 4], k2 = i, t2 = arr[i];
		double res = 2 * pi * ((k2 - 1) * t1 - (k1 - 1) * t2) / (t2 * t2 * t1 - t1 * t1 * t2);
		cout << i - 4 << " \t" << i << " \t" << res << endl;
	}
	
}
