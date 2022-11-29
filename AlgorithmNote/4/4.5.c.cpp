#include <cstdio>
#include <iostream>
using namespace std;

int main(){
	int size;
	while(~scanf("%d", &size)){
		int hashResult[101] = {0};
		for(int i = 0; i < size; i++){
			int number;
			cin >> number;
			hashResult[number] ++;
		}
		int amount;
		cin >> amount;
		for(int i = 0; i < amount; i++){
			int search;
			cin >> search;
			if(hashResult[search]) cout << "YES" << endl;
			else cout << "NO" << endl;
		}
	}
}
