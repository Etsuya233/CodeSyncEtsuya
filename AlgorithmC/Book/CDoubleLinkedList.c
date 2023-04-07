#include <stdio.h>
#include <stdlib.h>

typedef struct DList{
	int data;
	struct DList *next;
	struct DList *prev;
} *dlist, dnode;

void DListInit(dlist* head);
int Insert(dlist head, int location, int data);
int Append(dlist head, int data);
int Length(dlist head);
int Delete(dlist head, int location);
int Destroy(dlist* head);
int Change(dlist head, int location, int newValue);

int main(){
	dlist a;
	DListInit(&a);
	Append(a, 12);
	Append(a, 15);
	Append(a, 102);
	Append(a, 19);
	Change(a, 1, 101010);


}

void DListInit(dlist* head){
	(*head) = (dlist)malloc(sizeof(dnode));
	(*head)->data = 0;
	(*head)->next = NULL;
	(*head)->prev = NULL;
}

int Insert(dlist head, int location, int data){
	int i = -1;
	dlist p = head;
	while(head->next != NULL && i < location - 1){
		p = p->next;
		i++;
	}
	if(i != location - 1){
		printf("Syntax Error");
		return 0;
	}
	dlist temp;
	DListInit(&temp);
	temp->data = data;
	temp->next = p->next;
	if(p->next != NULL) p->next->prev = temp;
	p->next = temp;
	temp->prev = p;
	return 1;
}

int Append(dlist head, int data){
	Insert(head, Length(head), data);
	return 1;
}

int Length(dlist head){
	dlist p = head->next;
	int cnt = 0;
	while(p != NULL){
		cnt++;
		p = p->next;
	}
	return cnt;
}

int Delete(dlist head, int location){
	int i = -1;
	dlist p = head;
	while(p->next != NULL && i < location - 1){
		p = p->next;
		i++;
	}
	if(i != location - 1){
		printf("Syntax Error!");
		return 0;
	}
	dlist temp = p->next;
	if(temp->next) temp->prev = p;
	p->next = temp->next;
	free(temp);
	return 1;
}

int Destroy(dlist* head){
	dlist p = (*head), temp;
	while(p != NULL){
		temp = p;
		p = p->next;
		free(temp);
	}
	free(*head);
	*head = NULL;
	return 1;
}

int Change(dlist head, int location, int newValue){
	int i = -1;
	dlist p = head;
	while(p->next != NULL && i < location - 1){
		p = p->next;
		i++;
	}
	if(i != location - 1){
		printf("Syntax Error!");
		return 0;
	}
	p->next->data = newValue;
	return 1;
}