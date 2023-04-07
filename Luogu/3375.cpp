//#include <cstdio>
//#include <cstring>
#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

//KMP Algorithm
//ABBC CACA BA
//我是垃圾

int* getNext(string b, int length);
int* KMPFixed(string a, string b, int lengthA, int lengthB);
void getBorder(string a, int digit);
void getBetterNext(string a, int* next, int length);


int main(){
//	const int LENGTH = 1000004;
//	char a[LENGTH], b[LENGTH];
	string a, b;
//	scanf("%s%s", a, b);
	cin >> a >> b;
	int lengthA = a.length(), lengthB = b.length();
	int* arr = KMPFixed(a, b, lengthA, lengthB);
	for(int i = 1; i <= lengthB; i++){
		cout << arr[i] << " ";
	}

}

int* getNext(string b, int lengthB){
	int* next = (int*)malloc(sizeof(int) * (lengthB + 2));
	next[0] = -1;
	int i = 0, j = -1;
	while(i <= lengthB){
		if(j == -1 || b[i] == b[j]){
			i++;
			j++;
			next[i] = j;
		} else {
			j = next[j];
		}
	}
	return next;
}

int* KMPFixed(string a, string b, int lengthA, int lengthB){
	int *next = getNext(b, lengthB);
	int i = 0, j = 0;
	while(i < lengthA){
		if(j == -1 || a[i] == b[j]){
			i++;
			j++;
		} else {
			j = next[j];
		}
		if(j == lengthB){
			printf("%d\n", i - j + 1);
			i -= next[j - 1];
			i --;
			j = 0;
		}
	}
	return next;
}

void getBorder(string a, int digit){
	int i = 0, j = digit, flag = 0;
	while(i <= digit){
		if(a[i] == a[j]){
			i++;
			j--;
			flag = 1;
		} else {
			break;
		}
	}
	if(flag) printf("%d ", i);
	else printf("0 ");
}

void getBetterNext(string a, int* next, int length){
	int i = 1;
	for(; i < length; i++){
		if(a[i] == a[i - 1]){
			next[i] = next[i - 1];
		}
	}
}