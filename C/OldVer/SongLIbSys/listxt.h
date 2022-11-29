#ifndef _listxt_h_
#define _listxt_h_

struct txt
{
    char str[25];
    struct txt* next;
    struct txt* last;
};

typedef struct txt* txtPtr;
txtPtr TxtCreate(char* str);
void TxtAddB(txtPtr p, int location, char* str);
int TxtLength(txtPtr ptr);
void TxtDelB(txtPtr ptr, int location);
void TxtAddB(txtPtr ptr, int location, char* str);

#endif