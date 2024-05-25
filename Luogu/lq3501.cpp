#include <iostream>
using namespace std;

int main(){
	int maxCoin = -1;
	int maxVal = 0;
	int arr[4049] = {0};
	for(int i = 1; i <= 2023; i++){
		arr[i] += i;
		arr[i * 2] += i / 2;
		for(int j = i + 1; j <= 2023; j++){
			arr[i + j] += i;
		}
	} 	
	for(int i = 1; i <= 4048; i++){
		if(maxVal < arr[i]){
			maxVal = arr[i];
			maxCoin = i;
		}
	}
	cout << maxVal;
}
