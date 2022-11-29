#include <stdio.h>
//#include <stdlib.h>
//#include <time.h>

int main(){
	int num, N, input=1000, cnt=0;
	scanf("%d %d", &num, &N);
	
	while(input>0 && cnt<=N){
		scanf("%d", &input);
		if(input > num){
			printf("Too big!\n");
			cnt ++;
		} else if (input < num){
			printf("Too small!\n");
			cnt++;
		} else if (input <= 0){
			printf("Game Over");
				break;
		} else {
			cnt++;
			if(cnt == 1){
				printf("Bingo!\n");
				break;
			} else if (cnt <= 3 && cnt >1){
				printf("Lucky U\n");
				break;
			} else if (cnt > 3 && cnt <=N) {
				printf("Good guess!\n");
				break;
			}
		}
	}
	
	if( cnt > N || input < 0){
		printf("Game Over!!!");
	}
	
	return 0;
}
