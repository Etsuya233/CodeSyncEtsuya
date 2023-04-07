#include <cstdio>
//超市 on2
int main(){
    int arr[50005] = {0}, pre[50005] = {0};
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        int num;
        scanf("%d", &num);
        arr[i] = num;
        pre[i] = pre[i - 1] + num;
    }
    int max = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 0; j <= i - max; j++){
            if((pre[i] - pre[j]) % 7 == 0){
                if(i - j > max) max = i - j;
            }
        }
    }
    printf("%d", max);
}