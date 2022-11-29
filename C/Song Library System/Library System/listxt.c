#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <string.h>
#include "listxt.h"

txtPtr TxtCreate(char* str) {
    txtPtr p = (txtPtr)malloc(sizeof(struct txt));
    strcpy(p->str, str);
    p->next = NULL;
    p->last = p;
    return p;
}

void TxtAddB(txtPtr ptr, int location, char* str) {
    txtPtr p = (txtPtr)malloc(sizeof(struct txt));
    strcpy(p->str, str);
    int cnt = 0;
    txtPtr q = ptr;
    txtPtr r = NULL;
    for (; cnt < location; cnt++) {
        r = q;
        q = q->next;
    }
    p->next = q;
    if (location > 0) {
        r->next = p;
    }
    if (location == TxtLength(ptr)-1) {
        ptr->last = p;
    }
}

int TxtLength(txtPtr ptr) {
    int cnt = 1;
    txtPtr p = ptr;
    for (; p->next != NULL; cnt++) {
        p = p->next;
    }
    return cnt;
}

void TxtDelB(txtPtr ptr, int location) {
    txtPtr q = ptr, r = NULL;
    int cnt = 0;
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

char* TxtData(txtPtr ptr, int location) {
    txtPtr p = ptr;
    for (int cnt = 0; cnt < location; cnt++) {
        p = p->next;
    }
    return p->str;
}

