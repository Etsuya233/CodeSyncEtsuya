#include <iostream>
#include <cstring>
using namespace std;

//用字符串来存储数字
char str[100];  //存储原始字符串
char strmax[100];   //存储搜索过程中最大字符串
char strtemp[100];  //存储搜索时的字符串

int a, b, len;  //操作a的次数，操作b的次数，字符串长度

//比较函数，用来比较字符串形式的数字哪一个大，如果前面的大返回1，后面的大返回-1，相等返回0
int compare(char* number1, char* number2); 
//dfs函数，参数分别为dfs的当前的位数，所剩操作a和b的个数。
void dfs(int digit, int nowa, int nowb); 

int main(){
	cin >> str + 1 >> a >> b;   //输入，str+1的原因是可以避开str[0]，就不用管数组的索引位0的位置
	str[0] = 'a'; //随便赋一个值，我做的时候是'\0'，搞得我调了好久（（
	len = strlen(str + 1);  //获取原始字符串长度
	strcpy(strmax, str); //复制
	strcpy(strtemp, str); //复制
	dfs(1, a, b); //开始dfs
	cout << strmax + 1; //输出
	return 0;
}

void dfs(int digit, int nowa, int nowb){
	if(digit > len){ //假如已经从头到尾检查完，那就从strtemp和strmax中保留最大的
		int res = compare(strtemp, strmax);
		if(res > 0){
			strcpy(strmax, strtemp);
		}
		return;
	}
	int nowDigit = (number[digit] - '0'); //当前位置的数字
	int deltaa = 9 - nowDigit, deltab = 10 - deltaa; //a操作和b操作把当前位置的数字变成9的操作次数
	if(nowa >= deltaa){ //假如所剩的a操作次数多于所需的
		strtemp[digit] = '9';
		dfs(digit + 1, nowa - deltaa, nowb);
	}
	if(nowb >= deltab){ //假如所剩的b操作次数多于所需的
		strtemp[digit] = '9';
		dfs(digit + 1, nowa, nowb - deltab);
	}
	if(nowa <= deltaa && nowb <= deltab){ //假如a，b操作次数都不够，那就尽量把a操作用完，这样能使当前位的数字保持最大
		strtemp[digit] = nowDigit + '0' + nowa;
		dfs(digit + 1, 0, nowb);
	}
}

int compare(char* number1, char* number2){
	for(int i = 1; i <= len; i++){
		if(number1[i] > number2[i]) return 1;
		else if(number1[i] < number2[i]) return -1;
	}
	return 0;
}
