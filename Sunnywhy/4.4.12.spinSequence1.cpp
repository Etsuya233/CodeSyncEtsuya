#include <cstdio>
#include <iostream>
using namespace std;

int main(){
	int n;
	cin >> n;
	int number;
	cin >> number;
	int arr[n];
	for(int i = 0; i < n; i++) cin >> arr[i];
	
	
	int head = 0, foot = n - 1, half, flag = 0; //flag -> the sequence is a strict plus
	while(flag == 0){
		half = (head + foot) / 2;
		if(arr[half] == number) flag = 2; //2 represent the number has detected in the first stage
		
		if(arr[half] - arr[head] > 0){
			if(number >= arr[head] && number <= arr[half]){
				flag = 1;
				foot = half;
			} else {
				head = half;
				continue;
			}
		} else {
			if(number <= arr[foot] && number >= arr[half]) {
				flag = 1;
				head = half;
			} else{
				foot = half;
				continue;
			}
		}
	}
	while(flag == 1){
		half = (head + foot) / 2;
		if(arr[half] == number){
			cout << half << endl;
			break;
		}
		if(arr[half] > number){
			foot = half - 1;
		} else {
			head = half + 1;
		}
	}
	if(flag == 2) cout << half << endl;
	
	
}


