#include <iostream>
#include <algorithm>
using namespace std;

int n, ma, mb;
int a[100005] = {0}, b[100005] = {0};
int res[100005] = {0};
int moda = 1000000007;
int maxDigit = 0;
long long ans = 0;
long long hexa = 1;

int main(){
	fill(res, res + 100005, 2);
	cin >> n;
	cin >> ma;
	for(int i = ma; i >= 1; i--){
		cin >> a[i];
		res[i] = max(res[i], a[i] + 1);
	}
	cin >> mb;
	for(int i = mb; i >= 1; i--){
		cin >> b[i];
		res[i] = max(res[i], b[i] + 1);
	}
	maxDigit = max(ma, mb);
	for(int i = 1; i <= maxDigit; i++){
		ans = (ans + ((a[i] - b[i]) * hexa) % moda) % moda;
		hexa = (hexa * res[i]) % moda;
	}
	cout << ans;
	return 0;
}
