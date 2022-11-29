#include <cstdio>
#include <iostream>
using namespace std;

int binaryWave(int arr[], int length);
int factorsum_do(int number, int index);
int factorsum(int number);

int main(){
	int number;
	cin >> number;
	cout << factorsum(number);
}

int factorsum(int number){
	return factorsum_do(number, number - 1);
}

int factorsum_do(int number, int index){
	if(index == 1){
		return 1;
	} else {
		if(number % index == 0){
			return factorsum_do(number, index - 1) + index;
		} else {
			return factorsum_do(number, index - 1);
		}
	}
}

int binaryWave(int arr[], int length){
	int head = 0, foot = length - 1, half;
	while(head < foot){
		half = (head + foot) / 2;
		if(arr[half] <= arr[half - 1]) foot = half;
		else head = half + 1;
	}
	return head - 1;
}




