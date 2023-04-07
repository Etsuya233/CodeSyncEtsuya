#include <stdio.h>
#include <string.h>

int main(){
    char s1[] = "ababababca";
    char s2[] = "abababca";
    int next[10] = {0};
}

int KMP(char* s1, char* s2, int* next){
    int i = 0, j = 0, len1 = strlen(s1), len2 = strlen(s2);
    while(i < len1 && j < len2){
        if(s1[i] == s2[j]){
            i++;
            j++;
        } else {
            j = next[j];
        }
    }
    if(j == len2) return i - j;
    else return -1;
}

void getNext(char* s2, int* next){
    next[0] = -1;
    int i = 0, j = -1, len = strlen(s2);
    while(i < len - 1){
        if(s2[i] == s2[j] || j == -1){
            ++i;
            ++j;
            next[j] = j;
        } else {
            j = next[j];
        }
    }
}