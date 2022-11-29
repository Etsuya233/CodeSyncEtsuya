#include <stdio.h>
struct LNode {
    int val;
    struct LNode* next;
    struct LNode* last;
};

typedef struct LNode* LNodePtr;

LNodePtr ListCreate (int val);
void ListAdd (LNodePtr ptr, int val);
void ListAddB (LNodePtr ptr, int location, int val);
int ListData (LNodePtr ptr, int location);
void ListChange (LNodePtr, int location, int val);
void ListNodeDel (LNodePtr ptr);
void ListNodeDelB (LNodePtr ptr, int location);

int main(){
    LNodePtr test = ListCreate(5);
    ListAdd(test,7);
    ListAddB(test,1,6);
    printf("%d", ListData(test, 1));


}

LNodePtr ListCreate (int val){
    LNodePtr p = (LNodePtr)malloc(sizeof(struct LNode));
    p->val = val;
    p->next = NULL;
    p->last = p;
    return p;
}

void ListAdd (LNodePtr ptr, int val){
    LNodePtr p = (LNodePtr)malloc(sizeof(struct LNode));
    p->val = val;
    p->next = NULL;
    ptr->last->next = p;
}

void ListAddB (LNodePtr ptr, int location, int val){
    int cnt = 0;
    LNodePtr q = ptr;
    LNodePtr r = NULL; //用来记录前面一个指向结构体的指针
    LNodePtr p = (LNodePtr)malloc(sizeof(struct LNode));
    for(;cnt<location;cnt++){
        r = q;
        q = q->next;
    }
    p->val = val;
    p->next = q;
    if(cnt>0){
        r->next = p;
        p->next = q;
    }
}

int ListData (LNodePtr ptr, int location){
    LNodePtr q = ptr;
    int cnt = 0;
    for(;cnt<location;cnt++){
        q = q->next;
    }
    return q->val;
}

void ListChange (LNodePtr ptr, int location, int val){
    LNodePtr q = ptr;
    int cnt = 0;
    for(;cnt<location;cnt++){
        q = q->next;
    }
    q->val = val;
}

void ListNodeDel (LNodePtr ptr){
    LNodePtr q = ptr;
    while((q->next->next)!=NULL){   //获得倒数第二个数据的指针
        q = q->next;
    }
    if(q==ptr){
        printf("\nDo you mean ListFree()?\n");
    }else{
        q -> next = NULL;
    }
    ptr->last = q;
    free(q->next);
}

void ListNodeDelB (LNodePtr ptr, int location){
    int cnt = 0;
    LNodePtr q = ptr, r = NULL;
    for(;cnt<location;cnt++){
        r = q;
        q = q->next;
    }
    if(location!=0){
        r->next=q->next;
        //这里应该 free 掉 p
        if(q->next=NULL){
            ptr->last = q;
        }
    } else {
        ptr = ptr->next;
    }
}




