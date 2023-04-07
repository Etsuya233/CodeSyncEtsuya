#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct GeneralList{
	int tag;
	union {
		char atom;
		struct {
			struct GeneralList* hp;
			struct GeneralList* tp;
		};
	} un;
} *GList, GNode;

void DecomposeStr(char* hstr, char* str);
GList CreateGList(char* str);
GList NewGList(int type, char data);
void Traverse(GList head);
int Depth(GList head);
int NumberOfAtoms(GList head);
void DecomposeStr2(char* hstr, char* str);
GList CreateGList2(char* str);

int main(){
	char arr[] = "(((a,b,c),(d)),e)";
	char arr1[] = "(3)";
	GList a = CreateGList2(arr);
	Traverse(a);
	int depth = Depth(a);
	int atoms = NumberOfAtoms(a);
	printf("\n%d %d", depth, atoms);
	return 0;
}

void DecomposeStr(char* hstr, char* str){
	int l = 0, tag = 0, len = strlen(str);
	while(l < len){
		if(tag == 1 && str[l] == ',') break;
		if(str[l] == '(') tag++;
		if(str[l] == ')') tag--;
		l++;
	}
	//hstr
	//IMPORTANT! When the str -> "(3)", and the l should be 2, but without this sentence, the l will wrongly be 3.
	if(l == len) l--;
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
		for(int i = l + 1; i <= len - 2; i++, j++){
			str[j] = str[i];
		}
		str[j] = ')';
		str[j + 1] = '\0';
	}
}

GList CreateGList(char* str){
	int len = strlen(str);
	GList ret;
	if(len == 1){	//Is this an atom?
		ret = NewGList(0, str[0]);
	} else {
		char hstr[200];
		DecomposeStr2(hstr, str);
		ret = NewGList(1, '6');
		ret->un.hp = CreateGList(hstr);
		if(strcmp(str, "()") != 0){	//Is there are anything at the tail?
			ret->un.tp = CreateGList(str);
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
		ret->un.tp = NULL;
	} else {
		//Atom
		ret->tag = 0;
		ret->un.atom = data;
	}
	return ret;
}

void Traverse(GList head){
	if(head == NULL) return;
	if(head->tag){
		Traverse(head->un.hp);
		Traverse(head->un.tp);
	} else {
		printf("%c ", head->un.atom);
	}
}

int Depth(GList head){
	if(head == NULL) return 0;
	if(head->tag){
		int maximum = 0;
		GList p;
		for(p = head; p != NULL; p = p->un.tp){
			int temp = Depth(p->un.hp);
			if(temp > maximum) maximum = temp;
		}
		return maximum + 1;
	} else {
		return 0;
	}
}

int NumberOfAtoms(GList head){
	if(!head) return 0;
	if(head->tag){
//		int total = 0;
//		GList p;
//		for(p = head; p != NULL; p = p->un.tp){
//			total += NumberOfAtoms(p->un.hp);
//		}
//		return total;
		return NumberOfAtoms(head->un.hp) + NumberOfAtoms(head->un.tp);
	} else {
		printf("---%c", head->un.atom);
		return 1;
	}
}


void DecomposeStr2(char* hstr, char* str){
	int l = 0, len = strlen(str), tag = 0;
	while(l <= len - 2){
		if(tag == 1 && str[l] == ',') break;
		if(str[l] == '(') tag++;
		if(str[l] == ')') tag--;
		l++;
	}
	//hstr
	for(int i = 1; i < l; i++){
		hstr[i - 1] = str[i];
	}
	hstr[l - 1] = '\0';
	//str
	if(l == len - 2){
		strcpy(str, "()");
	} else {
		str[0] = '(';
		int j = 1;
		for(int i = l + 1; i <= len - 2; i++, j++){
			str[j] = str[i];
		}
		str[j] = ')';
		str[j + 1] = '\0';
	}
}

GList CreateGList2(char* str){
	int len = strlen(str);
	GList ret;
	if(len == 1){
		ret = NewGList(0, str[0]);
	} else {
		char hstr[200];
		DecomposeStr2(hstr, str);
		ret = NewGList(1, '6');
		ret->un.hp = CreateGList2(hstr);
		if(strcmp(str, "()") != 0){
			ret->un.tp = CreateGList2(str);
		}
	}
	return ret;
}