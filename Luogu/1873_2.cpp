// Success: sigh... watashi ha tsuyoidesu
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
	int n, m, answer, tallest = 0;
	cin >> n >> m;
	int arr[n];
	for(int i = 0; i < n; i++){
		cin >> arr[i];
		tallest = max(arr[i], tallest);
	}
	sort(arr, arr + n);
	int head = 0, foot = tallest;
	while(true){
		int half = (head + foot) / 2;
		long long gain = 0, gain_plus = 0;
		for(int i = upper_bound(arr, arr + n, half) - arr; i < n; i++){
			gain += arr[i] - half;
			int ret;
			gain_plus += ((ret = arr[i] - half - 1) >= 0)? ret: 0;
		}
		if(gain >= m && gain_plus < m){
			answer = half;
			break;
		} else if(gain_plus >= m){
			head = half;
		} else {
			foot = half;
		}
	}
	cout << answer << endl;
}
