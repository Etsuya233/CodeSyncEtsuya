#include <iostream>
#include <cstring>
using namespace std;

//���ַ������洢����
char str[100];  //�洢ԭʼ�ַ���
char strmax[100];   //�洢��������������ַ���
char strtemp[100];  //�洢����ʱ���ַ���

int a, b, len;  //����a�Ĵ���������b�Ĵ������ַ�������

//�ȽϺ����������Ƚ��ַ�����ʽ��������һ�������ǰ��Ĵ󷵻�1������Ĵ󷵻�-1����ȷ���0
int compare(char* number1, char* number2); 
//dfs�����������ֱ�Ϊdfs�ĵ�ǰ��λ������ʣ����a��b�ĸ�����
void dfs(int digit, int nowa, int nowb); 

int main(){
	cin >> str + 1 >> a >> b;   //���룬str+1��ԭ���ǿ��Աܿ�str[0]���Ͳ��ù����������λ0��λ��
	str[0] = 'a'; //��㸳һ��ֵ��������ʱ����'\0'������ҵ��˺þã���
	len = strlen(str + 1);  //��ȡԭʼ�ַ�������
	strcpy(strmax, str); //����
	strcpy(strtemp, str); //����
	dfs(1, a, b); //��ʼdfs
	cout << strmax + 1; //���
	return 0;
}

void dfs(int digit, int nowa, int nowb){
	if(digit > len){ //�����Ѿ���ͷ��β����꣬�Ǿʹ�strtemp��strmax�б�������
		int res = compare(strtemp, strmax);
		if(res > 0){
			strcpy(strmax, strtemp);
		}
		return;
	}
	int nowDigit = (number[digit] - '0'); //��ǰλ�õ�����
	int deltaa = 9 - nowDigit, deltab = 10 - deltaa; //a������b�����ѵ�ǰλ�õ����ֱ��9�Ĳ�������
	if(nowa >= deltaa){ //������ʣ��a�����������������
		strtemp[digit] = '9';
		dfs(digit + 1, nowa - deltaa, nowb);
	}
	if(nowb >= deltab){ //������ʣ��b�����������������
		strtemp[digit] = '9';
		dfs(digit + 1, nowa, nowb - deltab);
	}
	if(nowa <= deltaa && nowb <= deltab){ //����a��b�����������������Ǿ;�����a�������꣬������ʹ��ǰλ�����ֱ������
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
