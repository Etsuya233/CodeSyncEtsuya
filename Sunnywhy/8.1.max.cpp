#include <cstdio>
#include <algorithm>
using namespace std;

int labyrinth[7][7] = {0};
int sum = 0;
int n, m;
int targetStep;
int targetStrpFlag = 0;
int blockWeight[7][7] = {0};
int maxWeight = -11110;

void dfs(int now[7][7], int x, int y);
void dfs2(int now[7][7], int x, int y, int step);
void dfs3(int now[7][7], int x, int y, int weight);
int judgeFeasibility(int now[7][7]);

int main(){
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++){	//To graph the map
		for(int j = 1; j <= m; j++){
			int a;
			scanf("%d", &a);
			blockWeight[i][j] = a;
		}
	}
	
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m ; j++){
			labyrinth[i][j] = 1;
		}
	}
	//	for(int i = 1; i <= n; i++){	//To graph the map
	//		for(int j = 1; j <= m; j++){
	//			int a;
	//			scanf("%d", &a);
	//			labyrinth[i][j] = a? 0: 1;
	//		}
	//	}
	
	
	//	for(int i = 0; i < 7; i++){	//Print the map
	//		for(int j = 0; j < 7; j++){
	//			printf("%d", labyrinth[i][j]);
	//		}
	//		printf("\n");
	//	}
	//	dfs(labyrinth, 1, 1);
	//	printf("%d", sum);
	//	dfs2(labyrinth, 1, 1, 0);
	//	if(targetStrpFlag) printf("Yes");
	//	else printf("No");
	dfs3(labyrinth, 1, 1, 0);
	printf("%d", maxWeight);
	
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
	int myLabyrinth[7][7] = {0};
	std::copy(&now[0][0], &now[0][0] + 7 * 7, &myLabyrinth[0][0]);
	myLabyrinth[y][x] = 0;
	if(myLabyrinth[y + 1][x]){
		dfs(myLabyrinth, x, y + 1);
	}
	if(myLabyrinth[y][x + 1]){
		dfs(myLabyrinth, x + 1, y);
	}
	if(myLabyrinth[y - 1][x]){
		dfs(myLabyrinth, x, y - 1);
	}
	if(myLabyrinth[y][x - 1]){
		dfs(myLabyrinth, x - 1, y);
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

void dfs2(int now[7][7], int x, int y, int step){
	if(x == m && y == n){	//Pay attention to the relationship between x y m n
		sum++;
		if(step == targetStep) targetStrpFlag = 1;
		return;
	}
	if(!judgeFeasibility(now) || targetStrpFlag){
		return;
	}
	int myLabyrinth[7][7] = {0};
	std::copy(&now[0][0], &now[0][0] + 7 * 7, &myLabyrinth[0][0]);
	myLabyrinth[y][x] = 0;
	if(myLabyrinth[y + 1][x]){
		dfs2(myLabyrinth, x, y + 1, step + 1);
	}
	if(myLabyrinth[y][x + 1]){
		dfs2(myLabyrinth, x + 1, y, step + 1);
	}
	if(myLabyrinth[y - 1][x]){
		dfs2(myLabyrinth, x, y - 1, step + 1);
	}
	if(myLabyrinth[y][x - 1]){
		dfs2(myLabyrinth, x - 1, y, step + 1);
	}
}

void dfs3(int now[7][7], int x, int y, int weight){
	if(x == m && y == n){	//Pay attention to the relationship between x y m n
		maxWeight = max(maxWeight, weight + blockWeight[y][x]);
		printf("%d\n", maxWeight);
		return;
	}
	if(!judgeFeasibility(now)){
		return;
	}
	int myLabyrinth[7][7] = {0};
	std::copy(&now[0][0], &now[0][0] + 7 * 7, &myLabyrinth[0][0]);
	weight += blockWeight[y][x];
	myLabyrinth[y][x] = 0;
	if(myLabyrinth[y + 1][x]){
		dfs3(myLabyrinth, x, y + 1, weight);
	}
	if(myLabyrinth[y][x + 1]){
		dfs3(myLabyrinth, x + 1, y, weight);
	}
	if(myLabyrinth[y - 1][x]){
		dfs3(myLabyrinth, x, y - 1, weight);
	}
	if(myLabyrinth[y][x - 1]){
		dfs3(myLabyrinth, x - 1, y, weight);
	}
}

