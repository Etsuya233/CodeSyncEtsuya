#include <iostream>
#include <algorithm>
using namespace std;

int main(){
	int n, m, answer;
	cin >> n >> m;
	int arr[n];
	for(int i = 0; i < n; i++){
		cin >> arr[i];
	}
	sort(arr, arr + n);
	int head = 0, foot = n - 1;
	while(true){
		int half = head + (foot - head) / 2;
		long long gain = 0, gain_plus = 0;
		for(int i = upper_bound(arr, arr + n, arr[half]) - arr; i < n; i++){
			gain += arr[i] - arr[half];
			int ret;
			gain_plus += (ret = arr[i] - arr[half] - 1 >= 0)? ret: 0;;
		}
		if(gain > m && gain_plus < m){
			answer = arr[half];
			break;
		} else if(gain > m && gain_plus > m){
			head = half;
		} else {
			foot = half;
		}
	}
	cout << answer << endl;
	return 0;
}
