#include <cstdio>
#include <queue>
using namespace std;

typedef struct Pos{
	int x, y, cnt;
} pos;

int n, m, xx, yy;
int loc[2][8] = {-2, -1, 1, 2, 2, 1, -1,  -2, -1, -2, -2, -1, 1, 2, 2, 1};
int arr[402][402] = {0};
queue<pos> my;

int check(int x, int y);
void bfs();

int main(){
	scanf("%d%d%d%d", &n, &m, &xx, &yy);
	arr[xx][yy] = -1;
	pos start = {.x = xx, .y = yy, .cnt = 0};
	my.push(start);
	bfs();
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			if(arr[i][j] == 0) printf("-1   ");
			else if(arr[i][j] == -1) printf("0    ");
			else printf("%-5d", arr[i][j]);
		}
		printf("\n");
	}
	return 0;
}

int check(int x, int y){
	if(arr[x][y]) return 0;
	if(y < 1 || x < 1 || x > n || y > m) return 0;
	return 1;
}

void bfs(){
	pos a;
	while(!my.empty()) {``
		int x = my.front().x, y = my.front().y, cnt = my.front().cnt;
		for(int i = 0; i < 8; i++){
			a.cnt = cnt + 1;
			if(check(a.x = x  + loc[0][i], a.y = y + loc[1][i])){
				arr[a.x][a.y] = cnt + 1;
				my.push(a);
			}
		}
		my.pop();
	}
}
