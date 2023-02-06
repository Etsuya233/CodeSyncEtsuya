#include <cstdio>
//错的地方是没有提前把原点标记
typedef struct Location{
	int x, y, flag; //1 -> walked  2 -> stone
} loc;

int n, m, t, ans = 0;
loc start, stop;
loc map[7][7];
int xx[] = {0, 1, 0, -1};
int yy[] = {-1, 0, 1, 0};

void dfs(int x, int y);

int main(){
	//Initiate
	scanf("%d%d%d", &n, &m, &t);
	scanf("%d%d%d%d", &start.x, &start.y, &stop.x, &stop.y);
    map[start.y][start.x].flag = 1;
	for(int i = 0; i < t; i++){
		int a, b;
		scanf("%d%d", &a, &b);
		map[b][a].flag = 2;
	}
	//dfs
	dfs(start.x, start.y);
	printf("%d", ans);
	return 0;
}

void dfs(int x, int y){
	if(x == stop.x && y == stop.y){
		ans ++;
		return;
	}
	for(int i = 0; i < 4; i++){
		if(map[y + yy[i]][x + xx[i]].flag == 0 && y + yy[i] >= 1 && x + xx[i] >= 1 && y + yy[i] <= n && x + xx[i] <= m){
			map[y + yy[i]][x + xx[i]].flag = 1;
			dfs(x + xx[i], y + yy[i]);
			map[y + yy[i]][x + xx[i]].flag = 0;
		}
	}
}