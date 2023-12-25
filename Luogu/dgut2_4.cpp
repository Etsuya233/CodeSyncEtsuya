#include <iostream>
#include <algorithm>
using namespace std;

int n, d;
int hima[105] = {0};

int main(){
	cin >> n >> d;
	for(int i = 0; i < n; i++){
		char str[105];
		cin >> str;
		for(int j = 0; j < d; j++){
			if(str[j] == 'o') hima[j]++;
		}
	}
	int ans = 0;
	int now = 0;
	for(int i = 0; i <= d; i++){
		if(hima[i] == n) now++;
		else {
			ans = max(ans, now);
			now = 0;
		}
	}
	cout << ans;
	return 0;
}
