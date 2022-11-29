#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std;

int main(){
	int n, v, w;
	cin >> n >> v >> w;
	int potion[n];
	for(int i = 0; i < n; i++){
		cin >> potion[i];
	}
	
	sort(potion, potion + n);
	
	int sumV = 0;
	double sumP = 0;
	for(int i = 0; i < n; i++){
		double tempP;
		if(i == 0){
			tempP = potion[0];
		} else tempP = (sumP + potion[i]) / 2;
		if(tempP <= w){
			sumP = tempP;
			sumV += v;
		} else {
			break;
		}
	}
	printf("%d %.2f", sumV, sumP);
	
	
}
