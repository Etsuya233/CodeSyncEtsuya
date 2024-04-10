#include <cstdio>
using namespace std;

int arr[86410] = {0};

int main(){
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        int h1, m1, s1, h2, m2, s2;
        scanf("%d:%d:%d - %d:%d:%d", &h1, &m1, &s1, &h2, &m2, &s2);
        for(int j = h1 * 60 * 60 + m1 * 60 + s1; j <= h2 * 60 * 60 + m2 * 60 + s2 - 1; j++){
            arr[j] = 1;
        }
    }
    int cnt = 0;
    int calcing = 0;
    arr[86400] = 1;
    for(int i = 0; i <= 86400 - 1; i++){
        if(calcing == 0 && arr[i] == 0){
            int ii = i;
            calcing = 1;
            int s = ii % 60;
            ii /= 60;
            int m = ii % 60;
            ii /= 60;
            int h = ii % 24;
            if(h == 23 && m == 59 && s == 59){
                calcing = 0;
                continue;
            }
            if(cnt != 0) printf("\n");
            cnt++;
            printf("%02d:%02d:%02d - ", h, m, s);
        }
        if(calcing == 1 && arr[i] == 1){
            int ii = i;
            calcing = 0;
            int s = ii % 60;
            ii /= 60;
            int m = ii % 60;
            ii /= 60;
            int h = ii % 24;
            printf("%02d:%02d:%02d", h, m, s);
        }
    }
    if(calcing == 1){
        printf("23:59:59");
    }
    return 0;
}