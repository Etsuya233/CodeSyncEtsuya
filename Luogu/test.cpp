#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

char str[100];
char strmax[100];
char strtemp[100];
int a, b, len;

int getDigit(char* number, int digit);
int compare(char* number1, char* number2);
void dfs(int digit, int nowa, int nowb);

int main(){
	long long a = 1;
	for(long long i = 10000000000000; i <= 10000000050000; i++){
		cout << i << "\n";
	}
}


	/*
	deltaa deltab
	1，假如减的更优 deltab < deltaa
        且减的够 减！
        且减的不够而加的够 加！
        且两种都不够 加！
	2，假如加的更优
	    且加的够 加！
        且加的不够减的够 减！
        且两个都不够 加！
	*/
void dfs(int digit, int nowa, int nowb){
	if(digit > len || (nowa == 0 && nowb == 0)){
		int res = compare(strtemp, strmax);
		if(res > 0){
			strcpy(strmax, strtemp);
		}
		return;
	}
	int nowDigit = getDigit(str, digit);
	int deltab = 9 - nowDigit, deltaa = 10 - deltab;
	if(deltab < deltaa){
		if(nowb >= deltab){
			strtemp[digit] = '9';
			dfs(digit + 1, nowa, nowb - deltab);
		} else if(nowb < deltab && nowa >= deltaa){
			strtemp[digit] = '9';
			dfs(digit + 1, nowa - deltaa, nowb);
		} else {
			strtemp[digit] = nowDigit + '0' + nowa;
			dfs(digit + 1, 0, nowb);
		}
	} else if(deltab > deltaa){
		if(nowa >= deltaa){
			strtemp[digit] = '9';
			dfs(digit + 1, nowa - deltaa, nowb);
		} else if(nowa < deltaa && nowb >= deltab){
			strtemp[digit] = '9';
			dfs(digit + 1, nowa, nowb - deltab);
		} else {
			strtemp[digit] = nowDigit + '0' + nowa;
			dfs(digit + 1, 0, nowb);
		}
	} else {
		if(nowa >= deltaa){
			strtemp[digit] = '9';
			dfs(digit + 1, nowa - deltaa, nowb);
		}
		if(nowb >= deltab){
			strtemp[digit] = '9';
			dfs(digit + 1, nowa, nowb - deltab);
		}
		if(nowa <= deltaa && nowb <= deltab){
			strtemp[digit] = nowDigit + '0' + nowa;
			dfs(digit + 1, 0, nowb);
		}
	}
}

int getDigit(char* number, int digit){
	return number[digit] - '0';
}

int compare(char* number1, char* number2){
	for(int i = 1; i <= len; i++){
		if(number1[i] > number2[i]) return 1;
		else if(number1[i] < number2[i]) return -1;
	}
	return 0;
}
