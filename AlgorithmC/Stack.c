#include <stdio.h>
#include <stdlib.h>

typedef struct Stack{
	int *data;
	int p;
	int stackSize;
} *stack;

stack CreateStack(int sizeOfStack);
void DestroyStack(stack stack);
int StackEmpty(stack stack);
int StackLength(stack stack);
int GetTop(stack stack);
void ClearStack(stack stack);
int StackPush(stack stack, int value);
int StackPop(stack stack);

int main(){
	stack a = CreateStack(120);
	printf("Empty: %d\nSize: %d\n", StackEmpty(a), StackLength(a));
	for (int i = 0; i < 50; ++i){
		StackPush(a, i);
		printf("Push: %d\n", i);
	}
	printf("Empty: %d\nSize: %d\n", StackEmpty(a), StackLength(a));
	for (int i = 50; i > 0; i--){
		printf("Pop: %d\n", GetTop(a));
		StackPop(a);
	}
	printf("Empty: %d\nSize: %d\n", StackEmpty(a), StackLength(a));


}

/*
If the function below return 1 -> success or yes;
If the function below return 0 -> fail or no;
*/

stack CreateStack(int sizeOfStack){
	stack ret = (stack)malloc(sizeof(stack));
	ret->stackSize = sizeOfStack;
	ret->data = (int*)malloc(sizeof(int) * sizeOfStack);
	ret->p = 0;
	return ret;
}

void DestroyStack(stack stack){
	free(stack->data);
	free(stack);
}

int StackEmpty(stack stack){
	if(stack->p == 0) return 1;
	else return 0;
}

int StackLength(stack stack){
	return stack->p;
}

int GetTop(stack stack){
	return stack->data[stack->p - 1];
}

void ClearStack(stack stack){
	stack->p = 0;
}

int StackPush(stack stack, int value){
	if(stack->p >= stack->stackSize){
		return 0;
	}
	stack->data[stack->p] = value;
	stack->p ++;
	return 1;
}

int StackPop(stack stack){
	if(stack->p > 0){
		stack->p --;
		return 1;
	}
	return 0;
}