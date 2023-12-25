#include <iostream>
using namespace std;

int n;
char str[10];

int main(){
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> str;
		int h = (str[0] - '0') * 10 + str[1] - '0';
		int m = (str[3] - '0') * 10 + str[4] - '0';
		if(h >= 9) cout << "NO\n";
		else if(h == 8 && m > 0) cout << "NO\n";
		else cout << "YES\n";
	}
	return 0;
	
}
