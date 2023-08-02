#include <iostream>
#include <algorithm>
using namespace std;

int n, ma, mb;
int a[100005] = {0}, b[100005] = {0};
int res[100005] = {0};
int moda = 1000000007;
long long ans;
long long hexa = 1;

int main(){
	fill(res, res + 100005, 2);
	cin >> n;
	cin >> ma;
	for(int i = 0; i < ma; i++){
		cin >> a[i];
		res[i] = max(res[i], a[i] + 1);
	}
	cin >> mb;
	for(int i = ma - mb; i < ma; i++){
		cin >> b[i];
		res[i] = max(res[i], b[i] + 1);
	}
	ans = (a[ma - 1] - b[ma - 1]) % moda;
	hexa = res[ma - 1] % moda;
	for(int i = ma - 2; i >= 0; i--){
		ans = (ans + ((a[i] - b[i]) * hexa) % moda) % moda;
		hexa = (hexa * res[i]) % moda;
	}
	cout << ans;
	return 0;
}
