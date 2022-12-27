#include <iostream>
using namespace std;

int main(){
	int n;
	cin >> n;
	int last, now, sum;
	cin >> last;
	sum = last;
	for(int i = 1; i < n; i++){
		cin >> now;
		if(now > last) sum += (now - last);
		last = now;
	}
	cout << sum;
	return 0;
}
