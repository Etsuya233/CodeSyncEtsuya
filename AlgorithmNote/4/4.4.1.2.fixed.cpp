#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int main(){
	int amount[10];
	int count = 0;
	for(int i = 0; i < 10; i++){
		int number;
		cin >> number;
		amount[i] = number;
		count += number;
	}
	
//	int result[count];
	for(int i = 1; i < 10; i++){
		if(amount[i] > 0){
//			result[0] = i;
			cout << i;
			amount[i]--;
			break;
		}
	}
	
//	int digit = 1;
	for(int i = 0; i < 10; i++){
		while(amount[i] > 0){
			cout << i;
			amount[i] --;
		}
	}
}
