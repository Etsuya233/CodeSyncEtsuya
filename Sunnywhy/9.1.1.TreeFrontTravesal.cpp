#include <cstdio>
#include <cstdlib>

typedef struct node{
	int data;
	int layer = 0;
	node* lchild = NULL;
	node* rchild = NULL;
} Node;

int main(){
	
	
	
	
}

Node* newNode(int data){
	Node* ret = (Node*)malloc(sizeof(Node));
	ret->data = data;
	return ret;
}


