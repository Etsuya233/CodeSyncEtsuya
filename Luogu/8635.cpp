#include <iostream>
#include <cmath>
using namespace std;

int main(){
	int n;
	cin >> n;
	int sn = sqrt(n);
	for(int i = 0; i <= sn; i++){
		for(int j = 0; j <= sn; j++){
			for(int k = 0; k <= sn; k++){
				int q = n - i * i - j * j - k * k;
				if(q < 0) break;
				double sq = sqrt(q);
				if(sq - floor(sq) == 0.0){
					cout << i << " " << j << " " << k << " " << sq << "\n";
					return 0;
				}
			}
		}
	}
	return 0;
}
