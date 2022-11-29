#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;

void eightQueen(int index);

int amount = 8;
int hashX[8] = {0};
int result[8];
int count = 0;

int main(){
	//Calculate 8 queen
	eightQueen(0);
	
}

void eightQueen(int index){
//	if(index == amount){
//		int flag = 1;
//		for(int i = 0; i < amount; i++){
//			for(int j = i + 1; j < amount; j++){
//				if(abs(i - j) == abs(result[i] - result[j])){
//					flag = 0;
//				}
//			}
//		}
//		if(flag){
//			cout << count++ << " ";
//			for(int i = 0; i < amount; i++){
//				cout << result[i];
//			}
//			cout << "\n";
//		}
//		return;
//	}
	
	if(index == amount){
		cout << count++ << " ";
		for(int i = 0; i < amount; i++){
			cout << result[i];
		}
		cout << "\n";
		return;
	}


	for(int i = 0; i < amount; i++){
		if(!hashX[i]){
			int flag = 1;
			for(int j = 0; j < index; j++){
				if(abs(i - j) == abs(result[i] - result[j])){
					flag = 0;
					break;
				}
				if(flag){
					result[index] = i;
					hashX[i] = 1;
					eightQueen(index + 1);
					hashX[i] = 0;
				}
			}
		}
	}
}
