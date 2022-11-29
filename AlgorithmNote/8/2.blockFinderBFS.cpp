#include <cstdio>
#include <queue>
using namespace std;

typedef struct plot{
	int x, y;
} Plot;

int x[4] = {0, 0, 1, -1};
int y[4] = {1, -1, 0, 0};

int n, m, sum = 0;
int arr[101][101] = {0};
int walked[101][101] = {0};

void bfs(Plot a);

int main(){
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			scanf("%d", &arr[i][j]);
		}
	}
	//	printf("%d %d %d %d\n", arr[2][4], arr[0][4], arr[1][5], arr[1][3]);
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			if(walked[i][j]) continue;
			walked[i][j] = 1;
			if(arr[i][j]){
				Plot temp = {.x = j, .y = i};
				bfs(temp);
			}
		}
	}
	printf("%d", sum);
	return 0;
}

void bfs(Plot a){
	queue<Plot> my;
	my.push(a);
	sum++;
	while(!my.empty()){
		for(int i = 0; i < 4; i++){
			Plot temp;
			if(arr[temp.y = my.front().y + y[i]][temp.x = my.front().x + x[i]]){
				if(walked[temp.y][temp.x] == 0) {
					my.push(temp);
					walked[temp.y][temp.x] = 1;
				}
			}
			walked[temp.y][temp.x] = 1;
		}
		my.pop();
	}
}
