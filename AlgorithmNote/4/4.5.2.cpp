#include <cstdio>
#include <iostream>
using namespace std;

int main(){
	double eps = 1e-5;
	double head = 1, foot = 2;
	while(foot - head > eps){
		double half = (head + foot) / 2;
		if(half * half > 2){
			foot = half;
		} else {
			head = half;
		}
	}
	cout << foot;
	
}
