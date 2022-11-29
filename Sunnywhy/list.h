#ifndef _list_h_
#define _list_h_

struct LNode {
    int val;
    struct LNode* next;
    struct LNode* last;
};

typedef struct LNode* LNodePtr;

LNodePtr ListCreate(int val);
void ListAdd(LNodePtr ptr, int val);
void ListAddB(LNodePtr ptr, int location, int val);
int ListData(LNodePtr ptr, int location);
void ListChange(LNodePtr, int location, int val);
void ListNodeDel(LNodePtr ptr);
void ListNodeDelB(LNodePtr ptr, int location);
int ListLength(LNodePtr ptr);
void ListFree(LNodePtr ptr);

#endif
