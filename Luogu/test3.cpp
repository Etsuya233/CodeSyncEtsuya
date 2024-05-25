#include <iostream>
#include <algorithm>
using namespace std;

int arr[10005];

int main(){
	int n;
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> arr[i];
	}
	int a;
	cin >> a;
	cout << lower_bound(arr, arr + n, a, greater<int>()) - arr << "\n";
	
}
