#include <cstdio>
#include <queue>
using namespace std;

typedef struct block{
	int x, y, minStep = -1, walked = 1, uma = 0;
} Block;

int n, m, x, y;
int uma;
Block map[102][102];
int move1[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
int move2[8] = {-1, -2, -2, -1, 1, 2, 2, 1};
int barriar1[4] = {-1, 0, 1, 0};
int barriar2[4] = {0, -1, 0, 1};

void BFS();

int main(){
	scanf("%d%d%d%d", &n, &m, &x, &y);
	scanf("%d", &uma);
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			map[i][j].x = j;
			map[i][j].y = i;
			map[i][j].walked = 0;
		}
	}
	for(int i = 0; i < uma; i++){
		int a, b;
		scanf("%d%d", &a, &b);
		map[b][a].uma = 1;
		map[b][a].walked = 1;
	}
	BFS();
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			printf("%d ", map[i][j].minStep);
		}
		printf("\n");
	}
	return 0;
}

void BFS(){
	map[y][x].walked = 1;
	map[y][x].minStep = 0;
	queue<Block> my;
	my.push(map[y][x]);
	while(!my.empty()){
		for(int i = 0; i < 8; i++){
			if(!map[my.front().y + move2[i]][my.front().x + move1[i]].walked && !map[my.front().y + barriar2[i / 2]][my.front().x + barriar1[i / 2]].uma && my.front().y + move2[i] >= 1 && my.front().x + move1[i] >= 1){
				my.push(map[my.front().y + move2[i]][my.front().x + move1[i]]);
				map[my.front().y + move2[i]][my.front().x + move1[i]].walked = 1;
				map[my.front().y + move2[i]][my.front().x + move1[i]].minStep = my.front().minStep + 1;
				my.back().walked = 1;
				my.back().minStep = my.front().minStep + 1;
			}
		}
		my.pop();
	}
}

