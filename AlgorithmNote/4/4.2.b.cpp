#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
	int specimen;
	scanf("%d", &specimen);
	for(int i = 0; i < specimen; i++){
		int amount;
		int difNum = 1, difGroup = 1;
		int num[100] = {0}, group[100] = {0};
		scanf("%d", &amount);
		int data[amount][2];
		
		for(int j = 0; j < amount; j++){
			int number;
			scanf("%d", &number);
			data[j][0] = number;
			int k = 0;
			for(; k < difNum; k++){
				if(num[k] == number){
					break;
				}
			}
			if(k == difNum){
				num[difNum] = number; //num array note number from 1
				difNum ++; //finally --
			}
		}
		for(int j = 0; j < amount; j++){
			int gro;
			scanf("%d", &gro);
			data[j][1] = gro;
			int k = 0;
			for(; k < difGroup; k++){
				if(group[k] == gro) break;
			}
			if(k == difGroup){
				group[difGroup] = gro;
				difGroup ++;
			}
		}
		
		sort(num, num + difNum - 1);
		sort(group, group + difNum - 1);
		
		for(int i = 1; i < difGroup; i++){
			printf("%d={", group[i]);
			for(int j = 1; j < difNum; j++){
				printf("%d=", num[j]);
				int showTimes = 0;
				for(int k = 0; k < amount; k++){
//					printf("\n---- %d %d %d %d ----\n", data[k][1], group[j], data[k][0], num[j]);
					if(data[k][1] == group[i] && data[k][0] == num[j]) showTimes++; 
				}
				printf("%d", showTimes);
				if(j != difNum - 1) printf(",");
				else printf("}\n");
			}
		}
	}
}
