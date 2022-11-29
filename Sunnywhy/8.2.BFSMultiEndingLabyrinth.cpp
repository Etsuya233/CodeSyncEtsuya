#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;

typedef struct plot{
	int x, y;
} Plot;

int x[4] = {0, 0, 1, -1};
int y[4] = {1, -1, 0, 0};

int n, m;
int labyrinth[101][101] = {0};
int walked[101][101] = {0};
int ret[101][101] = {0};

void BFS();

int main(){
	std::fill(ret[0], ret[0] + 101 * 101, -1);
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			scanf("%d", &labyrinth[i][j]);
		}
	}
	BFS();
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			printf("%d ", ret[n][m]);
		}
	}
	
	
}

void BFS(){
	queue<Plot> my;
	Plot a = {.x = 1, .y = 1};
	my.push(a);
	int step = 0;
	while(!my.empty()){
		int len = my.size();
		for(int i = 0; i < len; i++){
			for(int j = 0; j < 4; j++){
				Plot temp;
				if(labyrinth[temp.y = my.front().y + y[j]][temp.x = my.front().x + x[j]]){
					my.push(temp);
					labyrinth[temp.y][temp.x] = 0;
					ret[temp.y][temp.x] = step;
				}
				if(temp.x == n && temp.y == m){
					return;
				}
			}
			my.pop();
		}
		step++;
	}
}
