#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct txt
{
    char str[25];
    struct txt* next;
    struct txt* last;
};

typedef struct txt* txtPtr;
int TxtLength(txtPtr ptr);
void TxtDelB(txtPtr ptr, int location);
void TxtAddB (txtPtr ptr, int location, char* str);
txtPtr TxtCreate(char* str);

int main(){
    char* init = "init";
    txtPtr a = TxtCreate(init);
    char* ad = "fucku";
    TxtAddB(a,1,ad);


}

txtPtr TxtCreate(char* str) {
    printf("********   Welcome to Song Library System   ********\n");
	printf("********           Initializing...          ********\n");
	printf("xxxxxxxx           Program Abort            xxxxxxxx\n"); //For test
	FILE* dat = fopen("dat.txt", "a+");	//open and read the file
	char init[25] = "init"; //init a list and initialize it
	txtPtr songs = TxtCreate(init);
	int amount = 0, cnt = 0;

	if (dat) {
		printf("Hey!\n");
		while (1) {
			char temp[24] = "";
			int ret;
			ret = fscanf(dat, "%s", temp);
			if (ret == EOF) {
				break;
			}
			TxtAddB(songs, cnt+1, temp);
			cnt++;
		}
		amount = cnt / 3;
		printf("******** There are %d data in our database  ********", amount);
	} else {
		printf("xxxxxxxx             File Error!            xxxxxxxx\n");
		printf("xxxxxxxx           Program Abort            xxxxxxxx\n");
	}
}

void TxtAddB(txtPtr ptr, int location, char* str) {
    txtPtr p = (txtPtr)malloc(sizeof(struct txt));
    strcpy(p->str, str);
    int cnt = 0;
    txtPtr q = ptr;
    txtPtr r = NULL;
    for (; cnt < location; cnt++) {
        r = ptr;
        q = q->next;
    }
    p->next = q;
    if (location > 0) {
        r->next = p;
    }
    if (location == TxtLength(ptr)) {
        ptr->last = q;
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
