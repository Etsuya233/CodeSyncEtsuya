#include <iostream>
using namespace std;

int main(){
	int n, a;
	cin >> n >> a;
	if(n == 0){
		cout << a;
	} else if(n > 1){
		if(a == 1) cout << "x^" << n;
		else if(a == -1) cout << "-x^" << n;
		else cout << a << "x^" << n;
		for(int i = n - 1; i > 1; i--){
			cin >> a;
			if(a > 1) cout << "+" << a << "x^" << i;
			else if(a == 1) cout << "+" << "x^" << i;
			else if(a == -1) cout << "-" << "x^" << i;
			else if(a == 0) continue;
			else cout << a << "x^" << i;
		}
		cin >> a;
		if(a > 1) cout << "+" << a << "x";
		else if(a == 1) cout << "+" << "x";
		else if(a == -1) cout << "-" << "x";
		else if(a == 0) ;
		else cout << a << "x";
		cin >> a;
		if(a > 0)
			cout << "+" << a;
		else if(a == 0) return 0;
		else
			cout << a;
	} else if(n == 1){
		if(a > 1) cout << a << "x";
		else if(a == 1) cout << "x";
		else if(a == -1) cout << "-" << "x";
		else if(a == 0) ;
		else cout << a << "x";
		cin >> a;
		if(a > 0)
			cout << "+" << a;
		else if(a == 0) return 0;
		else
			cout << a;
	}
}