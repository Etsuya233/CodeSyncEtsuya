#include <iostream>
using namespace std;

bool judge(int a);

int main(){
	int n, cnt = 0;
	cin >> n;
	for(int i = 1; i <= n; i++){
		if(judge(i)){
			cnt += i;
		}
	}
	cout << cnt << "\n";
	return 0;
}

bool judge(int a){
	while(a > 0){
		int b = a % 10;
		if(b == 2 || b == 0 || b == 1 || b == 9) return true;
		a /= 10;
	} 
	return false;
}
