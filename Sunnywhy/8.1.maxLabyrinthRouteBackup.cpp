#include <cstdio>

int labyrinth[7][7] = {0};
int sum = 0;
int n, m;

void dfs(int now[7][7], int x, int y);
int judgeFeasibility(int now[7][7]);

int main(){
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++){	//To graph the map
		for(int j = 1; j <= m; j++){
			int a;
			scanf("%d", &a);
			labyrinth[i][j] = a? 0: 1;
		}
	}

//	for(int i = 0; i < 7; i++){	//Print the map
//		for(int j = 0; j < 7; j++){
//			printf("%d", labyrinth[i][j]);
//		}
//		printf("\n");
//	}
	dfs(labyrinth, 1, 1);
	printf("%d", sum);
	return 0;
}

void dfs(int now[7][7], int x, int y){
	if(x == m && y == n){	//Pay attention to the relationship between x y m n
		sum++;
		return;
	}
	if(!judgeFeasibility(now)){
		return;
	}
	now[y][x] = 0;
	if(now[y + 1][x]){
		dfs(now, x, y + 1);
	}
	if(now[y][x + 1]){
		dfs(now, x + 1, y);
	}
	if(now[y - 1][x]){
		dfs(now, x, y - 1);
	}
	if(now[y][x - 1]){
		dfs(now, x - 1, y);
	}
}

int judgeFeasibility(int now[7][7]){
	int ret = 0;
	int x[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
	int y[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
	for(int i = 0; i < 8; i++){
		if(now[n + y[i]][m + x[i]]){
			ret = 1;
			break;
		}
	}
	return ret;
}