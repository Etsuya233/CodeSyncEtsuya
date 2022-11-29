#include <iostream>
using namespace std;

int count = 0;

int main(){
	int amount = 8;
	int hashTable[amount] = {0};
	int result[amount] = {0};
	
	
	
	
	
}

void nQueen(int index, int amount, int hashTable[], int result[]){
//	if(index == amount){
//		
//		int flag = 0;
//		for(int i = 1; i < amount; i++){
//			int y = 0;
//			for(int j = i; j >= 0 ; j--){
//				if(result[j] == i - y) flag++;
//			}
//			if(flag > 1){
//				count++;
//				break;
//			}
//		}
//		for(int i = 1; i < amount; i++){
//			int y = i;
//			for(int j = amount - 1; j > 0; j--){
//				if(result[j] == )
//			}
//		}
//	}
	
	for(int i = 0; i < amount; i++){
		if(!hashTable[i]){
			result[index] = i;
			hashTable[index] = 1;
			nQueen(index + 1, amount, hashTable, result);
			hashTable[index] = 0;
		}
	}
	
}
