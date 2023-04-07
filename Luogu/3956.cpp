#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int m, n;
int arr[1005][1005] = {0};
int cost[1005][1005];
int xxx[] = {0, 1, 0, -1};
int yyy[] = {-1, 0, 1, 0};

void bfs();

int main(){
	fill(cost[0], cost[0] + 1005 * 1005, -1);
	cin >> m >> n;
	int y, x, c;
	for(int i = 0; i < n; i++){
		cin >> y >> x >> c;
		arr[y][x] = c? 2: 1;
	}
	bfs();
	cout << cost[m][m];
}

void bfs(){
	typedef struct Position{
		int x = 1, y = 1, c = 0;
	} Pos;
	Pos temp;
	cost[1][1] = 0;
	queue<Pos> my;
	my.push(temp);
	while(!my.empty()){
		int y = my.front().y, x = my.front().x, c = my.front().c;
		int yy, xx;
		for(int i = 0; i < 4; i++){
			if((yy = y + yyy[i]) > 0 && y + yyy[i] <= m && (xx = x + xxx[i]) > 0 && x + xxx[i] <= m){
				if(arr[y][x] == 1 || arr[y][x] == 2){
					if((arr[yy][xx] == 1 || arr[yy][xx] == 2) && arr[yy][xx] == arr[y][x] && (cost[yy][xx] == -1 || cost[yy][xx] > c)){
						cost[yy][xx] = c;
						temp.c = c;
						temp.y = yy;
						temp.x = xx;
						my.push(temp);
					} else if((arr[yy][xx] == 1 || arr[yy][xx] == 2) && arr[yy][xx] != arr[y][x] && (cost[yy][xx] == -1 || cost[yy][xx] > c + 1)){
						cost[yy][xx] = c + 1;
						temp.c = c + 1;
						temp.y = yy;
						temp.x = xx;
						my.push(temp);
					} else if((!arr[yy][xx] || arr[yy][xx] >= 3) && (cost[yy][xx] == -1 || cost[yy][xx] > c + 2)){
						cost[yy][xx] = c + 2;
						arr[yy][xx] = arr[y][x] + 2;
						temp.c = c + 2;
						temp.y = yy;
						temp.x = xx;
						my.push(temp);
					}
				} else {
					if((arr[yy][xx] == 1 || arr[yy][xx] == 2) && arr[yy][xx] == arr[y][x] - 2 && (cost[yy][xx] == -1 || cost[yy][xx] > c)){
						cost[yy][xx] = c;
						temp.c = c;
						temp.y = yy;
						temp.x = xx;
						my.push(temp);
					} else if((arr[yy][xx] == 1 || arr[yy][xx] == 2) && arr[yy][xx] != arr[y][x] && (cost[yy][xx] == -1 || cost[yy][xx] > c + 1)){
						cost[yy][xx] = c + 1;
						temp.c = c + 1;
						temp.y = yy;
						temp.x = xx;
						my.push(temp);
					}
				}
			}
		}
		my.pop();
	}
}