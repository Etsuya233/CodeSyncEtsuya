//什么垃圾题目
#include <string>
#include <iostream>
using namespace std;

int main(){
	string str;
	int matched[105] = {0};
	cin >> str;
	for(int i = 0; i < str.length(); i++){
		if(str[i] == ')'){
			for(int j = i - 1; j >= 0; j--){
				if(str[j] == '(' && matched[j] == 0){
					matched[j] = matched[i] = 1;
				}
			}
		}
		if(str[i] == ']'){
			for(int j = i - 1; j >= 0; j--){
				if(str[j] == '[' && matched[j] == 0){
					matched[j] = matched[i] = 1;
				}
			}
		}
	}
	for(int i = 0; i < str.length(); i++){
		if(matched[i]) cout << str[i];
		else {
			if(str[i] == '(' || str[i] == ')') cout << "()";
			if(str[i] == '[' || str[i] == ']') cout << "[]";
		}
	}
}