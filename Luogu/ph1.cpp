#include <iostream>
using namespace std;

double pi =  3.14159265358979323846;

int main(){
	int n;
	cin >> n;
	double sum = 0;
	for(int i = 0; i < n; i++){
		double k1, t1, k2, t2;
		cin >> k1 >> t1 >> k2 >> t2;
		double res = 2 * pi * ((k2 - 1) * t1 - (k1 - 1) * t2) / (t2 * t2 * t1 - t1 * t1 * t2);
		cout << res << endl;
		sum += res;
	}
	cout << sum / n << endl;
	
	
}
