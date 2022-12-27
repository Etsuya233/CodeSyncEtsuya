#include <cstdio>
#include <string>
#include <iostream>
using namespace std;

string func(int number);

int main(){
	int n;
	cin >> n;
	cout << func(n);
	return 0;
}

string func(int number){
	string ret, temp;
	int bin[16] = {0};
	int flag = 0;
	
	//Split the binary
	for(int i = 0; number > 0; i++){
		bin[i] = number % 2;
		number /= 2;
	}
	
	//Travesal
	for(int i = 15; i >= 0; i--){
		if(bin[i]){
			if(flag) ret += "+";
			if(i >= 2){
				ret += "2(";
				ret += func(i);
				ret += ")";
			} else if(i == 1){
				ret += "2";
			} else {
				ret += "2(";
				ret += i + '0';
				ret += ")";
			}
			flag = 1;
		}
	}	
	return ret;
}
