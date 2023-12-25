#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

typedef long long ll;

ll n, m;
ll p[100050];
ll a[100050], c[100050], b[100050];
ll sum = 0;
ll times[100050] = {0};
ll mp[100050] = {0};
ll charge[100050] = {0};

int main(){
	cin >> n >> m;
	for(int i = 1; i <= m; i++){
		cin >> p[i];
	}
	//计算多少次回本
	for(int i = 1; i <= n - 1; i++){
		cin >> a[i] >> b[i] >> c[i];
		times[i] = ceil(1.0 * c[i] / (a[i] - b[i]));
	}
	//计算每条铁路线经过了多少次
	for(int i = 2; i <= m; i++){
		ll a = p[i - 1], b = p[i];
		mp[min(a, b)] ++;
		mp[max(a, b)] --;
	}
	for(int i = 1; i <= n - 1; i++){
		mp[i] += mp[i - 1];
		if(mp[i] >= times[i]){
			sum += c[i];
			charge[i] = b[i];
		} else {
			charge[i] = a[i];
		}
	}
	//计算金钱
	for(int i = 1; i <= n - 1; i++){
		charge[i] += charge[i - 1];
	}
	for(int i = 2; i <= m; i++){
		ll a = p[i - 1], b = p[i];
		sum += charge[max(a, b) - 1] - charge[min(a, b) - 1];
	}
	cout << sum;
	return 0;
}
