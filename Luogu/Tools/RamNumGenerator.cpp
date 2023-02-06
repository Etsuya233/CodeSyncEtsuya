#include <cstdio>
#include <random>
#include <ctime>
#include <cstdlib>

int main(){
    int small, big, amount;
    srand((unsigned)time(NULL));    //Change the seed
    printf("Please enter the smallest number:");
    scanf("%d", &small);
    printf("Please enter the biggest number:");
    scanf("%d", &big);
    printf("How many number do you want:");
    scanf("%d", &amount);
    for(int i = 0; i < amount; i++){
        printf("%d ", rand() % (big - small + 1) + small);
    }
}