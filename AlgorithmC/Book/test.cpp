#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 定义广义表节点类型
typedef struct GeneralList {
    int tag;
    struct GeneralList *tp;
    union {
        char atom;
        struct GeneralList *hp;
    } un;
} GNode, *GList;

// 函数原型声明
GList CreateGList(char *s);
void DecomposeStr(char *hstr, char *str);

// 根据给定字符串创建广义表
GList CreateGList(char *s) {
    GList p = NULL;
    if (strlen(s) == 1) { // 原子
        p = (GList)malloc(sizeof(GNode));
        p->tag = 0;
        p->un.atom = s[0];
    } else { // 列表
        char hstr[100];
        DecomposeStr(hstr, s);
        if (strlen(hstr) == 1) { // 头部为原子
            p = (GList)malloc(sizeof(GNode));
            p->tag = 0;
            p->un.atom = hstr[0];
        } else { // 头部为列表
            p = (GList)malloc(sizeof(GNode));
            p->tag = 1;
            p->un.hp = CreateGList(hstr);
        }
        if (strcmp(s, "()") != 0) { // 尾部不为空
            p->tp = CreateGList(s);
        }
    }
    return p;
}

// 分离字符串中第一个子表并更新剩余部分
void DecomposeStr(char *hstr, char *str) {
    int l = 0, tag = 0, len = strlen(str);
    while (l <= len - 2) {
        if (tag == 1 && str[l] == ',') break;
        if (str[l] == '(') tag++;
        if (str[l] == ')') tag--;
        l++;
    }
    for (int i=1; i<=l-1; i++) {
      hstr[i-1]= str[i];
   }
   hstr[l-1]='\0';
   if(str[l]!=','){
       strcpy(str,"()");
   }else{
       str[0]='(';
       int j=1;
       for(int i=l+1;i<len-1;i++,j++){
           str[j]= str[i];
       }
       str[j]=')';
       str[j+1]='\0';
   }
}