#include <iostream>
#include <cstdio>
using namespace std;

int main(){
    int n;
    double p;
    int f = 1;
    cin >> n >> p;
    for(int i = 1; i <= n; i++){
        double now;
        cin >> now;
        if(now < p){
            if(f == 0){
                printf("\n");
            }
            f = 0;
            printf("On Sale! %.1f", now);
        }
    }
}