#include <stdio.h>

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2);

struct ListNode {
     int val;
     struct ListNode *next;
};

int main(){
    struct ListNode l1, l2;
    
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    int num1=0,num2=0,sum;
    while(l1!=NULL){
        int mul=1;
        num1=num1+(l1->val)*mul;
        mul*=10;
        l1=l1->next;
    }
    while(l2!=NULL){
        int mul=1;
        num2=num2+(l2->val)*mul;
        mul*=10;
        l2=l2->next;
    }
    sum=num1+num2;
    struct ListNode* L = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* ret = L;
    int digit=sum%10;
    L->val=digit;
    L->next=NULL;
    for(;sum>0;sum/=10){
        struct ListNode* p = (struct ListNode*)malloc(sizeof(struct ListNode));
        int digit = sum%10;
        p->val=digit;
        p->next=NULL;
        L->next=p;
        L=p;
    }
    return ret;
}