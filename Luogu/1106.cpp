#include <cstdio>
#include <algorithm>
#include <string>
#include <iostream>
using namespace std;

int main(){
	string num;
	cin >> num;
	int k;
	sort(num.begin(), num.end());
	cin >> k;
	string::iterator it = num.end();
	for(int i = 0; i < k; i++){
		num.erase(it - 1, it);
		it--;
	}
	int flag = 0;	//Judge if there is olny 0
	it = num.begin();
	while(true){
		if(*it != 0){
			flag = 1;
			break;
		}
		it++;
	}
	if(flag){
		for(; it != num.end(); it++){
			cout << *it;
		}
	} else {
		cout << 0;
	}
}
