#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;

ll n, f;
ll moda = 100000000;
int dp[2][1005] = {0};
int arr[2005];

int main(){
	cin >> n >> f;
	for(int i = 0; i < n; i++) cin >> arr[i];
	dp[0][0] = 0;
	for(int i = 0; i < n; i++){
		int now = arr[i] % f;
		for(int j = 0; j < f; j++){
			dp[i % 2][j] = (dp[(i + 1) % 2][j] + dp[(i + 1) % 2][(j + f - now) % f] + (now == j)) % moda;
//			cout << dp[i % 2][j] << "\t";
		}
//		cout << "\n";
	}
	cout << dp[(n - 1) % 2][0] % moda;
	return 0;
}
