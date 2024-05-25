#include <iostream>
using namespace std;

int arr[10005];
int n;
int cnt = 0;

int main(){
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> arr[i];
		if(i != arr[i]) cnt++;
	}
	cout << (cnt + 1) / 2 << "\n";
}
