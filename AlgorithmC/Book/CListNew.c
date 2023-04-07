#include <stdio.h>
#include <stdlib.h>

typedef struct List{
	int data;
	struct List* next;
} *list, node;

void NewList(list* head);
int Insert(list head, int location, int data);
int Delete(list head, int location);
int Change(list head, int location, int newValue);
int Destroy(list* head);
int Length(list head);
int Append(list head, int data);

int main(){
	list a;
	NewList(&a);
	Append(a, 12);
	Append(a, 19);
	Append(a, 1);
	list tempa = a->next;
	list tempb = a->next->next;
	printf("%p %p", tempa, tempb);
	Destroy(&a);
	printf("%d", a);

}

void NewList(list* head){
	*head = (list)malloc(sizeof(node));
	(*head)->next = NULL;
	(*head)->data = 0;
}

int Insert(list head, int location, int data){
	int i = -1;
	list p = head;
	while(p->next != NULL && i < location - 1){
		p = p->next;
		i++;
	}
	if(i != location - 1){
		printf("Syntax Error!");
		return 0;
	}
	list temp;
	NewList(&temp);
	temp->data = data;
	temp->next = p->next;
	p->next = temp;
	return 1;
}

int Delete(list head, int location){
	int i = -1;
	list p = head;
	while(p->next != NULL && i < location - 1){
		p = p->next;
		i++;
	}
	if(i != location - 1){
		printf("Syntax Error!");
		return 0;
	}
	list temp = p->next;
	int ret = temp->data;
	p->next = temp->next;
	free(temp);
	return ret;
}

int Change(list head, int location, int newValue){
	int i = -1;
	list p = head;
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

int Destroy(list* head){
	list now = NULL;
	list p = *head;
	while(p != NULL){
		now = p;
		p = p->next;
		free(now);
	}
	free(*head);
	*head = NULL;
	return 1;
}

int Length(list head){
	int cnt = 0;
	list p = head;
	while(p->next != NULL){
		p=p->next;
		cnt++;
	}
	return cnt;
}

int Append(list head, int data){
	int length = Length(head);
	Insert(head, length, data);
	return 1;
}