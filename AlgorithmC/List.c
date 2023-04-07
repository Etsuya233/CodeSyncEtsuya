#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode{
    int size;
    int value;
    struct ListNode* next;
} listNode, *list;

int main(){


}

list newList(){
    list ret = (list)malloc(sizeof(listNode));
    ret->size = 0;
    ret->next = NULL;
    ret->value = 0;
    return ret;
}

int addList(list root, int value, int location){
    if(root == NULL || location < 0 || location > root->size) return 0;
    list now = root->next, last = root;
    for(int i = 0; i < location; i++){
        last = now;
        now = now->next;
    }
    list temp = newList();
    temp->value = value;
    last->next = temp;
    temp->next = now;
    root->size++;
    return 1;
}

int appendList(list root, int value){
    if(root == NULL) return 0;
    list now = root->next;
    for(int i = 0; i < root->size - 1; i++){
        now = now->next;
    }
    list temp = newList();
    temp->value = value;
    now->next = temp;
    root->size ++;
    return 1;
}

int destroyList(list root){
    if(root == NULL) return 0;
    list now = root, nexta = root->next;
    while(now->next != NULL){
        
    }
}