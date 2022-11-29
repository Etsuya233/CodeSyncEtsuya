#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "list.h"

LNodePtr ListCreate(int First_val) {
    LNodePtr p = (LNodePtr)malloc(sizeof(struct LNode));
    p->val = First_val;
    p->next = NULL;
    p->last = p;
    return p;
}

void ListAdd(LNodePtr ptr, int val) {
    LNodePtr p = (LNodePtr)malloc(sizeof(struct LNode));
    p->val = val;
    p->next = NULL;
    ptr->last = p;
}

void ListAddB(LNodePtr ptr, int location, int val) {
    int cnt = 0;
    LNodePtr q = ptr;
    LNodePtr r = NULL; //用来记录前面一个指向结构体的指针
    LNodePtr p = (LNodePtr)malloc(sizeof(struct LNode));
    for (; cnt < location; cnt++) {
        r = q;
        q = q->next;
    }
    p->val = val;
    p->next = q;
    if (cnt > 0) {
        r->next = p;
        p->next = q;
    }
}

int ListData(LNodePtr ptr, int location) {
    LNodePtr q = ptr;
    int cnt = 0;
    for (; cnt < location; cnt++) {
        q = q->next;
    }
    return q->val;
}

void ListChange(LNodePtr ptr, int location, int val) {
    LNodePtr q = ptr;
    int cnt = 0;
    for (; cnt < location; cnt++) {
        q = q->next;
    }
    q->val = val;
}

void ListNodeDel(LNodePtr ptr) {
    LNodePtr q = ptr;
    if (ListLength(ptr) == 1) {
        ListFree(ptr);
    }
    else {
        while ((q->next->next) != NULL) {   //获得倒数第二个数据的指针
            q = q->next;
        }
        free(q->next);
        q->next = NULL;
        ptr->last = q;
    }
}

void ListNodeDelB(LNodePtr ptr, int location) {
    int cnt = 0;
    LNodePtr q = ptr, r = NULL;
    for (; cnt < location; cnt++) {
        r = q;
        q = q->next;
    }
    if (location != 0) {
        r->next = q->next;
        if (q->next = NULL) {
            ptr->last = r;
        }
        free(q);
    }
    else { //to judge the target whether is the first
        ptr = ptr->next;
    }
}

int ListLength(LNodePtr ptr) {
    int cnt = 1;
    LNodePtr p = ptr;
    for (; p->next != NULL; cnt++) {
        p = p->next;
    }
    return cnt;
}

void ListFree(LNodePtr ptr) {
    LNodePtr p = ptr;
    while (p->next != NULL) {
        LNodePtr q = p;
        p = p->next;
        free(q);
    }
    free(p);  //the last selected pointer
}