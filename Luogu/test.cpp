#include <iostream>
<<<<<<< HEAD
#include <cstring>
using namespace std;

char str[100005];
int len = 0;

int dp[100005][26] = {0};

int main(){
	cin >> len >> str;
	dp[0][str[0] - 'a'] = 1;
	for(int i = 1; i < len; i++){
		for(int j = 0; j < 26; j++){
			if(j == str[i] - 'a') dp[i][j] = dp[i - 1][j] + 1;
			else dp[i][j] = dp[i - 1][j];
		}
	}
//	for(int i = 0; i < 26; i++){
//		cout << dp[len - 1][i];
//	}
	long long ans = 0;
	for(int i = 0; i < len; i++){
		for(int j = 0; j < 26; j++){
			if(j == str[i] - 'a') continue;
			long long temp = 1L * (dp[len - 1][j] - dp[i][j]);
			ans += temp * (temp - 1) / 2;
		}
	}
	cout << ans << "\n";
	return 0;
=======
using namespace std;

bool isPrime(int n) {
    if (n <= 1) return false;
    if (n <= 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) return false;
    }
    return true;
}

int main() {
    int count = 0;
    int num = 2;
    while (count < 937) {
        if (isPrime(num)) {
            count++;
        }
        num++;
    }
    cout << "937是从2开始的第" << count << "个质数。" << endl;
    return 0;
>>>>>>> 44a5f682f12c778f6c39350be7d3199e6facd7cc
}
