#include <iostream>
#include <algorithm>
using namespace std;

int dp[4][2] = {{0, 0}, {1, 0}, {2, 1}};
int n;
int moda = 10000;

int main(){
	cin >> n;
	for(int i = 3; i <= n; i++){
		int k = i % 4;
		dp[k][0] = ((dp[(k + 4 - 1) % 4][0] + (dp[(k + 4 - 1) % 4][1] + dp[(k + 4 - 1) % 4][1]) % moda) % moda + dp[(k + 4 - 2) % 4][0]) % moda;
		dp[k][1] = (dp[(k + 4 - 2) % 4][0] + dp[(k + 4 - 1) % 4][1]) % moda;
	}
	cout << dp[n % 4][0] % moda;
	return 0;
}
