#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct GeneralList{
	int tag;
	struct GeneralList* tp;
	union{
		char atom;
		struct GeneralList* hp;
	} un;
} GNode, *GList;

void DecomposeStr(char* hstr, char* str);
GList CreateGeneralList(char* str);
GList NewGList(int type, char data);

int main(){
	char s[] = "(a,(b,c))";
	GList a = CreateGeneralList(s);
	printf("qwq");

}

void DecomposeStr(char* hstr, char* str){
	int l = 0, tag = 0, len = strlen(str);
	while(l <= len - 2){
		if(tag == 1 && str[l] == ',') break;
		if(str[l] == '(') tag++;
		if(str[l] == ')') tag--;
		l++;
	}
	//hstr
	for(int i = 1; i <= l - 1; i++){
		hstr[i - 1] = str[i];
	}
	hstr[l - 1] = '\0';
	//str
	if(str[l] != ','){
		strcpy(str, "()");
	} else {
		str[0] = '(';
		int j = 1;
		for(int i = l + 1; i < len - 1; i++, j++){
			str[j] = str[i];
		}
		str[j] = ')';
		str[j + 1] = '\0';
	}
}

GList CreateGeneralList(char* str){
	int len = strlen(str);
	GList ret = NULL;
	if(len == 1){
		ret = NewGList(0, str[0]);
	} else {
		char hstr[200];
		DecomposeStr(hstr, str);
		if(strlen(hstr) == 1){  //同层处理
			ret = NewGList(0, hstr[0]);
		} else {
			ret = NewGList(1, '\0');
			ret->un.hp = CreateGeneralList(hstr);
		}
		if(strcmp(str, "()") != 0){
			ret->tp = CreateGeneralList(str);
		}
	}
	return ret;
}

GList NewGList(int type, char data){
	GList ret = (GList)malloc(sizeof(GNode));
	if(type){
		//Sheet
		ret->tag = 1;
		ret->un.hp = NULL;
		ret->tp = NULL;
	} else {
		//Atom
		ret->tag = 0;
		ret->un.atom = data;
		ret->tp = NULL;
	}
	return ret;
} 