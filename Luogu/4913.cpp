#include <cstdio>

int main(){
	int bt[100001] = {0}, big = 0, n;
	int loc[100001] = {0, 1};
	scanf("%d", &n);
	for(int i = 1; i <= n; i++){
		int location = loc[i];
		int lloc = location * 2;
		int rloc = location * 2 + 1;
		int lnode, rnode;
		scanf("%d%d", &lnode, &rnode);
		bt[lloc] = lnode;
		bt[rloc] = rnode;
		loc[lnode] = lloc;
		loc[rnode] = rnode;
		big = (big > rloc)? big: rloc;
	}
	int square = 0;
	while(big > 0){
		big /= 2;
		square ++;
	}
	printf("%d", square - 1);
}