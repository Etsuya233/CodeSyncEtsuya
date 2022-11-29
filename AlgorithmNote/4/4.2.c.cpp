#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
	int hashResult[50000] = {0};
	int times;
	while(~scanf("%d", &times)){
		int numberList[times] = {0};
		for(int i = 0; i < times; i++){
			cin >> numberList[i];
			hashResult[numberList[i]] ++;
		}
		
		int flag = 0;	//To detect if the program has found a unique number
		for(int i = 0; i < times; i++){
			if(hashResult[numberList[i]] == 1){
				cout << numberList[i] << "\n";
				flag = 1;
				break;
			}
		}
		if(flag) continue;
		printf("None\n");
	}
	
	
}
