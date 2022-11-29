#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
	int distance;
	while(true){
		cin >> distance;
		if(distance == 0) break;
		double price = 0;
		if(distance <= 4) price = 10;
		if(distance > 4 && distance <= 8) price = 10 + (distance - 4) * 2;
		if(distance > 8){
			while(distance > 8){
				price += 18;
				distance -= 8;
			}
			if(distance > 4){
				price += 10 + (distance - 4) * 2;
			} else {
				price += 2.4 * distance;
			}
//			price += 18;
//			distance -= 8;
//			while(1){
//				if(distance - 8 > 0){
//					price += 18;
//					distance -= 18;
//				} else {
//					if(distance > 4){
//						price += 10 + (distance - 4) * 2;
//						break;
//					} else {
//						price += 2.4 * distance;
//						break;
//					}
//				}
//			}
		}
		cout << price << endl;
	}
	
}
