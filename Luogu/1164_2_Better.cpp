#include <iostream>
using namespace std;

int m, n;
int price[101];
int dp2[1001] = {0};

int main(){
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> price[i];
    }
	for(int i = 1; i <= n; i++){
		for(int j = m; j >= 1; j--){
			if(price[i] == j) dp2[j] = dp2[j] + 1;
			else if(price[i] < j) dp2[j] = dp2[j] + dp2[j - price[i]];
		}
	}
    cout << dp2[m];
}