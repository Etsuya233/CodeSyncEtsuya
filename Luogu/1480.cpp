#include <iostream>
#include <cstring>
using namespace std;

typedef long long ll;

char str[10000];
ll b;
ll now;
ll left;
ll arr[10000];
ll ans[10000];
ll digit;

int main(){
	cin >> str;
	digit = strlen(str);
	cin >> b;
	for(int i = 0; i < digit; i++){
		arr[i] = str[i] - '0';
	}
	arr[digit] = ans[digit] = 0;
	now = arr[0];
	for(ll i = 0; i < digit; i++){
		ans[i] = now / b;
//		cout << now / b;
		if(ans[i] > 0){
			now = now % b;
		}
		now = now * 10 + arr[i + 1];
	}
	ll i = 0;
	ll cnt = 0;
	for( ; i < digit && ans[i] == 0; i++);
	for( ; i < digit; i++){
		cout << ans[i];
		cnt++;
	}
	if(cnt == 0) cout << 0;
	return 0;
}
