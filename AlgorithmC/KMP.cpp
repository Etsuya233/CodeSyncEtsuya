#include <cstdio>
#include <cstring>
#include <cstdlib>

//KMP Algorithm

int* getNext(char *b, int length);
int KMP(char* a, char* b, int lengthA, int lengthB);

int main(){
	const int LENGTH = 100000;
	char a[LENGTH], b[LENGTH];
	scanf("%s%s", a, b);
	int lengthA = (int)strlen(a), lengthB = (int)strlen(b);
	printf("%d", KMP(a, b, lengthA, lengthB));
}

int* getNext(char *b, int lengthB){
	int* next = (int*)malloc(sizeof(int) * (lengthB + 1));
	next[0] = -1;
	int i = 0, j = -1;
	while(i < lengthB){
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

int KMP(char* a, char* b, int lengthA, int lengthB){
	int *next = getNext(b, lengthB);
	int i = 0, j = 0;
	while(i < lengthA){
		if(j == -1 || a[i] == b[j]){
			i++;
			j++;
		} else {
			j = next[j];
		}
		if(j == lengthB) return i - j;
	}
	return -1;
}