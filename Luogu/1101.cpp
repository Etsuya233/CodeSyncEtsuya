#include <cstdio>

int n;
char arr[102][102] = {""};
char key[] = "yizhong";
char answer[102][102] = {""};

int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%s", arr[i]);
    }
    int loc = 0;
    //->
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(arr[i][j] == key[loc]){
                loc ++;
            } else {
                loc = 0;
            }
            if(loc == 7){
                for(int k = j - 7; k == j; k++){
                    answer[i][k] = key[k - j + 7];
                }
                loc = 0;
            }
            if(j == n - 1) loc = 0;
        }
    }


}