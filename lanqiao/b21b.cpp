#include <iostream>
using namespace std;

int prime[10000000] = {0};
int vis[20210610] = {0};
int p[10] = {0, 0, 1, 1, 0, 1, 0, 1, 0, 0};

void primeFinder();

int main(){
    primeFinder();
    int cnt = 0;
    for(int i = 1; i <= prime[0]; i++){
        int a = prime[i];
        bool flag = true;
        while(a > 0){
            if(p[a % 10] == 0){
                flag = false;
                break;
            }
            a /= 10;
        }
        if(flag){
            cnt++;
        }
    }
    cout << cnt << "\n";
    return 0;
}

void primeFinder(){
    for(int i = 2; i <= 20210605; i++){
        if(vis[i] == 0){
            vis[i] = 1;
            prime[++prime[0]] = i;
        }
        for(int j = 1; j <= prime[0] && i * prime[j] <= 20210605; j++){
            vis[i * prime[j]] = 1;
            if(i % prime[j] == 0) break;
        }
    }
}