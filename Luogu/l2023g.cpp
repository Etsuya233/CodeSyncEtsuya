#include <iostream>
#include <cstring>
using namespace std;

typedef long long ll;

ll n;
char str[500005];
char h, t;
ll tt[500005] = {0};
ll len;
ll ans = 0;

int main(){
	cin >> n >> (str + 1) >> h >> t;
	str[0] = 'A';
	len = strlen(str);
	len--;
	for(int i = 1; i <= len; i++){
		if(str[i] == t) tt[i] ++;
		tt[i] += tt[i - 1]; 
	}
	for(int i = 1; i <= len - n + 1; i++){
		if(str[i] != h) continue;
		ans += tt[len] - tt[i + n - 2];
	}
	
	cout << ans << "\n";
}
