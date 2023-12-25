#include <iostream>
using namespace std;

int d, n, m;
int arr[50005] = {0};

bool check(int md);

int main(){
	cin >> d >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> arr[i];
	}
	arr[n + 1] = d;
	int l = 1, r = d, mid;
	while(l < r){
		mid = (l + r) / 2;
		if(check(mid)){
//			cout << mid << " OK\n";
			l = mid + 1;
		} else {
//			cout << mid << " Dame\n";
			r = mid;
		}
	}
	cout << l - 1;
}

bool check(int md){
//	cout << "\t" ;
	int cnt = 0, now = 0;
	for(int i = 1; i <= n + 1; i++){
		if(arr[i] - arr[now] >= md){
			now = i;
		} else {
//			cout << arr[i] << " ";
			cnt++;
		}
	}
//	cout << "\n";
	if(cnt > m){
		return false;
	} else {
		return true;
	}
}
