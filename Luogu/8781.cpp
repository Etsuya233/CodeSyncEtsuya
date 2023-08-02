#include <iostream>
using namespace std;

typedef long long ll;

int main(){
	ll n;
	cin >> n;
	/*
	1  1
	2  2 2
	3  4 2 4
	4  6 4 4 6
	5  8 6 4 6 8
	6  10 8 6 6 8 10
	*/
	int start = 2 * (n - 1);
	if(start == 0) start = 1;
	int times = (n + 1) / 2;
	ll pr = start;
	if(n % 2){
		for(int i = 0; i < times; i++){
			cout << pr << "\n";
			pr -= 2;
		}
		pr += 2;
		for(int i = 0; i < times - 1; i++){
			pr += 2;
			cout << pr << "\n";
		}
	} else {
		for(int i = 0; i < times; i++){
			cout << pr << "\n";
			pr -= 2;
		}
		pr += 2;
		for(int i = 0; i < times; i++){
			cout << pr << "\n";
			pr += 2;
		}
	}
	return 0;
}
