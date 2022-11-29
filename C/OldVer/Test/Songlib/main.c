#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"
#include "listxt.h"

int main() {
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





	return 0;
}

void init() {

}
