#include <cstdio>
#include <queue>
using namespace std;

typedef struct block{
	int x, y, minStep = 0, walked = 1, uma = 0;
} Block;

int n, m, x, y;
int uma;
Block map[102][102];
int move1[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
int move2[8] = {-1, -2, -2, -1, 1, 2, 2, 1};
int barriar1[4] = {-1, 0, 1, 0};
int barriar2[4] = {0, -1, 0, 1};

int main(){
	scanf("%d%d%d%d", &n, &m, &x, &y);
	scanf("%d", &uma);
	for(int i = 0; i < uma; i++){
		int a, b;
		scanf("%d%d", &a, &b);
		map[b][a].uma = 1;
	}
	
//	BFS();
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			printf("%d ", map[i][j].minStep);
		}
		printf("\n");
	}
	return 0;
}

