#include <cstdio>
#include <iostream>
#include <string.h>
using namespace std;

void reverse_string_do(char str[], char str_copy[], int length, int index);
void reverse_string(char str[], int length);

int main(){
	char str[101];
	cin >> str;
	reverse_string(str, strlen(str));
	cout << str;
	
	
}

void reverse_string(char str[], int length){
	char str_copy[101];
	strcpy(str_copy, str);
	reverse_string_do(str, str_copy, length, 0);
}

void reverse_string_do(char str[], char str_copy[], int length, int index){
	if(index == length) return;
	else{
		str[index] = str_copy[length - index - 1];
		reverse_string_do(str, str_copy, length, index + 1);
	}
}
