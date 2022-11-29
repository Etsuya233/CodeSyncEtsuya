#include <stdio.h>
#include <iostream>
using namespace std;

void magicPocket(int index, int sum);

int amount, price[20];
int count = 0, money = 0;

int main(){
	while(~scanf("%d", &amount)){
		for(int i = 0; i < amount; i++){
			cin >> price[i];
		}
		magicPocket(0, 40);
		cout << count;
	}
	
}

void magicPocket(int index, int sum){
	if(sum == 0){
		count ++;
		return;
	}
	if(index >= amount) return;
	if(sum - price[index] >= 0) magicPocket(index + 1, sum - price[index]);
	magicPocket(index + 1, sum);
}
