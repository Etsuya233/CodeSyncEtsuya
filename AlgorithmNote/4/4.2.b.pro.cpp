#include <stdio.h>
#include <algorithm>
#include <iostream>
using namespace std;

int main(){
	int n, m, num[100], group[100];
	while(~scanf("%d", &n)){
		int hashResult[100][2100] = {0};
		for(int i = 0; i < n; i++){
			scanf("%d", &m);
			for(int j = 0; j < m; j++){
				scanf("%d", &num[j]);
			}
			for(int j = 0; j < m; j++){
				scanf("%d", &group[j]);
				hashResult[num[j]][group[j]] ++;
			}
		}
		
		sort(num, num + m);
		sort(group, group + m);
		
		for(int i = 0; i < m; i++){
			if(i == 0 || group[i] != group[i - 1]){
				printf("%d={", group[i]);
			} else continue;
			for(int j = 0; j < m; j++){
				if(j == 0){
					printf("%d=%d", num[j], hashResult[num[j]][group[i]]);
				}
				if(j > 0 && num[j] != num[j - 1]){
					printf(",%d=%d", num[j], hashResult[num[j]][group[i]]);
				}
				if(j == m - 1){
					printf("}\n");
				}
			}
		}
	}
	
}
