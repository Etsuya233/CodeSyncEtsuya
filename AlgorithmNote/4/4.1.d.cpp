#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

int main(){
	while(true){
		char str[200];
		cin.getline(str, 200);
		sort(str, str + strlen(str));
		cout << str;
	}
}
