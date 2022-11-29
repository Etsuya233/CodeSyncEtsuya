#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

int main(){
	char origin[10000];
	char needToDelete[255];
	int hashCharList[255] = {0};
	while(true){
		gets(origin);
		scanf("%s", needToDelete);
		for(int i = 0; i < (int)strlen(needToDelete); i++){
			hashCharList[(int)needToDelete[i]] ++;
		}
		char originFixed[10000];
		int location = 0;
		for(int i = 0; i < (int)strlen(origin); i++){
			if(hashCharList[(int)origin[i]] == 0){
				originFixed[location] = origin[i];
				location ++;
			}
		}
		originFixed[location] = '\0';
		
		printf("%s\n", originFixed);
	}
	
	
	
}
