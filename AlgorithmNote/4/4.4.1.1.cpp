#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

typedef struct mooncake{
	double stock;
	double unitPrice;
	double price;
} mooncake;

bool cmpUnitPrice(mooncake a, mooncake b);

int main(){
	int n;
	double need;
	cin >> n;
	cin >> need;
	mooncake array[n];
	
	for(int i = 0; i < n; i++){
		cin >> array[i].stock;
	}
	for(int i = 0; i < n; i++){
		cin >> array[i].price;
		array[i].unitPrice = array[i].price / array[i].stock;
	}
	
	sort(array, array + 8, cmpUnitPrice);
	
	double income = 0;
	for(int i = 0; i < n && need > 0; i++){
		if(array[i].stock > need){
			income += array[i].unitPrice * need;
			break;
		} else {
			income += array[i].price;
			need -= array[i].stock;
		}
	}
	
	printf("%.2f", income);
}

bool cmpUnitPrice(mooncake a, mooncake b){
	return (a.unitPrice > b.unitPrice);
}
