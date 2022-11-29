#include <cstdio>

typedef struct node{
	int times = 0; 
	int next;
} Node;

int main(){
	int p1, p2, n;
	Node arr[100000];
	scanf("%d%d%d", &p1, &p2, &n);
	for(int i = 0; i < n; i++){
		int p, next;
		char c;
		scanf("%d %c %d", &p, &c, &next);
		arr[p].next = next;
	}
	for(int i = p1; i != -1; i = arr[i].next){
		arr[i].times ++;
	}
	for(int i = p2; i != -1; i = arr[i].next){
		arr[i].times ++;
	}
	int i = p1;
	for( ; i != -1; i = arr[i].next){
		if(arr[i].times > 1) break;
	}
	printf("%d", i);
	
	return 0;
}

