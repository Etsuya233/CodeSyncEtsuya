#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

void FullPermutation(int index);
const int maxn = 11;
int n, P[maxn], hashTable[maxn] = {0};

int main(){
	n = 5;
	FullPermutation(1);
}

void FullPermutation(int index){
	if(index == n + 1){
		cout << "(";
		for(int i = 1; i <= n; i++){
			cout << " " << P[i] << " ";
		}
		cout << ")\n";
		return;
	}
	
	for(int i = 1; i <= n; i++){
		if(!hashTable[i]){
			P[index] = i;
			hashTable[i] = 1;
			FullPermutation(index + 1);
			hashTable[i] = 0;
		}
	}
}
