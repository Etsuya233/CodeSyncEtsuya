#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int main(){
	int cash[5][2] ={{50,0},{20,0},{10,0},{5,0},{1,0}};
	int total;
	cin >> total;
	while(total >= 50){
		total -= 50;
		cash[0][1] ++;
	}
	while(total >= 20){
		total -= 20;
		cash[1][1] ++;
	}
	while(total >= 10){
		total -= 10;
		cash[2][1] ++;
	}
	while(total >= 5){
		total -= 5;
		cash[3][1] ++;
	}
	while(total >= 1){
		total -= 1;
		cash[4][1] ++;
	}
	
	int flag = 0;
	for(int i = 0; i < 5; i++){
		if(cash[i][1] > 0){
			if(flag) printf("+");
			flag = 1;
			printf("%d*%d", cash[i][0], cash[i][1]);
		}
	}
	
	
}
