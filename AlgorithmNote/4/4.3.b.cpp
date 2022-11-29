#include <stdio.h>
#include <iostream>
using namespace std;

int fibonacci(int piece);

int main(){
	int stack;
	cin >> stack;
	for(int i = 1; i <= stack; i++){
		for(int j = 1; j < stack - i + 1; j++){
			cout << "  ";
		}
		for(int j = 1; j <= i * 2 - 1; j++){
			cout << fibonacci(j);
			if(j == i * 2 - 1) cout << "\n";
			else cout << " ";
		}
	}

	
}

int fibonacci(int piece){
	if(piece == 1){
		return 1;
	} else if(piece == 2){
		return 2;
	} else {
		return fibonacci(piece - 1) + fibonacci(piece - 2);
	}
}
