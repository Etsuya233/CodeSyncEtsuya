#include <iostream>
#include <cstring>
using namespace std;

typedef long long ll;

char str[31];
ll len;
ll n;

int calcLayer(int num);

int main(){
	cin >> str >> n;
	len = strlen(str);
	cout << str[calcLayer(n) - 1];
	return 0;
}

int calcLayer(int num){
	ll layer = 0;
	ll sum = len;
	ll res;
	for( ; sum < num; sum *= 2, layer++);
	if(layer <= 0){
		return num;
	} else {
		ll mid = sum / 2;
		if(num == mid + 1) res = mid;
		else res = num - mid - 1;
		return calcLayer(res);
	}
}