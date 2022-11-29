#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
using namespace std;

int main(){
	
	int n, m;
	cin >> n >> m;
	int hashEachBook[m] = {0};
	int favouriteBook[n] = {0};
	for(int i = 0; i < n; i++){
		cin >> favouriteBook[i];
		hashEachBook[favouriteBook[i]]++;
	}
	for(int i = 0; i < n; i++){
		if(hashEachBook[favouriteBook[i]] - 1) cout << hashEachBook[favouriteBook[i]] - 1 << "\n";
		else cout << "BeiJu\n";
	}
	
	
}
