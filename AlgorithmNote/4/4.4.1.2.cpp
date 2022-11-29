#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std;

int main(){
	int number[10];
	for(int i = 0; i < 10; i++){
		cin >> number[i];
	}
	
	sort(number, number + 10);
	
	int result[10];
	for(int i = 0; i < 10; i++){
		if(number[i] > 0){
			result[0] = number[i];
			number[i] = -1;
			break;
		}
	}
	
	int digit = 1;
	for(int i = 0; i < 10; i++){
		if(number[i] >= 0) result[digit++] = number[i];
	}
	
	for(int i = 0; i < 10; i++) cout << result[i];
}
