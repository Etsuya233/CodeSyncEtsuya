#include <cstdio>
#include <queue>
#include <algorithm>
#include <windows.h>
using namespace std;

typedef struct Location{
	int x, y, t, lastTime;
} loc;

int n, nowTime = 0, used = 0;
int map[604][604] = {0};
loc arr[50002];
queue<loc> my;
int xx[5] = {0, 0, 1, 0, -1};
int yy[5] = {0, -1, 0, 1, 0};

bool cmpTime(loc a, loc b);

int main(){
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf("%d%d%d", &arr[i].x, &arr[i].y, &arr[i].t);
	}
	sort(arr, arr + n, cmpTime);
	while(arr[used].t == 0){
		for(int i = 0; i < 5; i++){
			if(arr[used].y + yy[i] >= 0 && arr[used].x + xx[i] >= 0) map[arr[used].y + yy[i]][arr[used].x + xx[i]] = -1;
		}
		used ++;
	}
	loc zero = {.x = 0, .y = 0, .lastTime = 1};
	if(map[0][0] != -1) my.push(zero);
	while(used < n){
		while(arr[used].t == nowTime){
			for(int i = 0; i < 5; i++){
				if(arr[used].y + yy[i] >= 0 && arr[used].x + xx[i] >= 0) map[arr[used].y + yy[i]][arr[used].x + xx[i]] = -1;
			}
			used ++;
		}
		while(my.front().lastTime == nowTime + 1){
			if(map[my.front().y][my.front().x] == -1){
				my.pop();
				continue;
			}
			if(map[my.front().y + 1][my.front().x] != -1 && map[my.front().y + 1][my.front().x] != 1){
				loc temp = {.x = my.front().x, .y = my.front().y + 1, .lastTime = nowTime + 2};
				map[my.front().y + 1][my.front().x] ++;
				my.push(temp);
			}
			if(map[my.front().y][my.front().x + 1] != -1 && map[my.front().y][my.front().x + 1] != 1){
				loc temp = {.x = my.front().x + 1, .y = my.front().y, .lastTime = nowTime + 2};
				map[my.front().y][my.front().x + 1] ++;
				my.push(temp);
			}
			my.pop();
		}
		system("cls");
		for(int i = 0; i < 40; i++){
			for(int j = 0; j < 40; j++){
				if(map[i][j] == 0) printf(". ");
				if(map[i][j] > 0) printf("! ");
				if(map[i][j] == -1) printf("X ");
			}
			printf("\n");
		}
		printf("%d", nowTime);
		Sleep(1500);
		nowTime ++;
	}
	for(int i = 0; i <= nowTime; i++){
		for(int j = 0; j <= i; j++){
			if(map[j][i - j] > 0){
				printf("%d", i);
				return 0;
			}
		}
	}
	printf("-1");
	return 0;
}

bool cmpTime(loc a, loc b){
	return a.t < b.t;
}
