#include <cstdio>
#include <queue>
using namespace std;

typedef struct plot{
	int x, y, step = 0;
} Plot;

int labyrinth[101][101] = {0};
int walked[101][101] = {0};
int n, m;
int x[4] = {0, 0, 1, -1};
int y[4] = {1, -1, 0, 0};
Plot S, T;
int minStep = 100000007;
int flag = 0;

void bfs(Plot now);

int main(){
	scanf("%d%d", &n, &m);
	char temp[12];
	for(int i = 1; i <= n; i++){
		scanf("%s", temp);
		for(int j = 1; j <= m; j++){
			if(temp[j - 1] == '.') labyrinth[i][j] = 1;
			if(temp[j - 1] == 'S'){
				labyrinth[i][j] = 2;
				S.x = j;
				S.y = i;
			}
			if(temp[j - 1] == 'T'){
				labyrinth[i][j] = 3;
				T.x = j;
				T.y = i;
			}
		}
	}
//	scanf("%d %d %d %d", &S.x, &S.y, &T.x, &T.y);
	bfs(S);
	printf("%d", flag? minStep: -1);
	return 0;
}

void bfs(Plot now){
	int feasibility = 0;
	for(int i = 0; i < 4; i++){
		if(labyrinth[T.y + y[i]][T.x + x[i]]){
			feasibility = 1;
			break;
		}
	}
	if(!feasibility) return;
	walked[now.y][now.x] = 1;
	queue<Plot> my;
	my.push(now);
	while(!my.empty()){
		Plot temp;
		for(int i = 0; i < 4; i++){
			if (T.x == my.front().x && T.y == my.front().y) {
				minStep = my.front().step;
				flag = 1;
				return;
			}
			if(labyrinth[temp.y = my.front().y + y[i]][temp.x = my.front().x + x[i]]){
				if(walked[temp.y][temp.x] == 0) {
					temp.step = my.front().step + 1;
					my.push(temp);
				}
			}
			labyrinth[temp.y][temp.x] = 0;
		}
		my.pop();
	}
}

/*
  
  5 5
  .....
  .*.*.
  .*S*.
  .***.
  ...T*
  3 3 4 5
 */
