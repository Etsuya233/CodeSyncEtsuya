#include <stdio.h>
#include <iostream>
using namespace std;

int eatChocolate(int piece);

int main(){
	cout << eatChocolate(6);
	
	
	
}

int eatChocolate(int piece){
	if(piece == 1){
		return 1;
	} else if(piece == 2){
		return 2;
	} else {
		return eatChocolate(piece - 1) + eatChocolate(piece - 2);
	}
}
