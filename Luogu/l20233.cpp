#include <iostream>
using namespace std;

int o[10005] = {0};
int v[10005] = {0};
int n;
int sum = 0;

int judge(int mid);

int main(){
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> o[i] >> v[i];
		sum += v[i];
	}
	//min
	int l = 1, r = 1e9, mid;
	while(l < r){
		mid = (l + r) / 2;
		int res = judge(mid);
		if(res > sum){
			l = mid + 1;
		} else {
			r = mid;
		}
	}
	cout << l << " ";
	//max
	l = 1;
	r = 1e9;
	while(l < r){
		mid = (l + r) / 2;
		int res = judge(mid);
		if(res >= sum){
			l = mid + 1;
		} else {
			r = mid;
		}
	}
	cout << l - 1 << "\n";
	return 0;
}

int judge(int mid){
	int ret = 0;
	for(int i = 1; i <= n; i++){
		ret += o[i] / mid; 
	}
	return ret;
}
