#include <iostream>
#include <cmath>
using namespace std;

typedef long long ll;

ll n;

int main(){
	cin >> n;
	for(int i = 0; i <= 63; i++){
		for(int j = 0; j <= 39; j++){
			ll now = pow(2, i) * pow(3, j);
			//ÅÐ¶ÏÒç³ö
			if(now == n){
				cout << "Yes\n";
				return 0;
			} else if(now > n || now <= 0) break;
		}
	}
	cout << "No\n";
	return 0;
}
