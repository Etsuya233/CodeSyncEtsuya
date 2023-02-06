#include <cstdio>
#include <queue>
#include <algorithm>
#include <windows.h>
using namespace std;

typedef struct Location{
	int x, y, t, lastTime;
} loc;

int n, nowTime = 0, used = 0;
int map[304][304] = {0};
int vis[304][304] = {0};
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
	vis[0][0] = 1;
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
			for(int i = 1; i < 5; i++){
				if(my.front().y + yy[i] >= 0 && my.front().x + xx[i] >= 0 && map[my.front().y + yy[i]][my.front().x + xx[i]] != -1 && vis[my.front().y + yy[i]][my.front().x + xx[i]] == 0){
					vis[my.front().y + yy[i]][my.front().x + xx[i]] = nowTime;
					loc temp = {.x = my.front().x + xx[i], .y = my.front().y + yy[i], .lastTime = nowTime + 2};
					map[my.front().y + yy[i]][my.front().x + xx[i]] ++;
					my.push(temp);
				}
			}
			my.pop();
		}
//		system("cls");
//		for(int i = 0; i < 40; i++){
//			for(int j = 0; j < 40; j++){
//				if(map[i][j] == 0) printf(". ");
//				if(map[i][j] > 0) printf("! ");
//				if(map[i][j] == -1) printf("X ");
//			}
//			printf("\n");
//		}
//		printf("%d", nowTime);
//		Sleep(1000);
		nowTime ++;
	}
	int ans = 0x7fffffff;
	int found = 0;
	for(int i = 0; i < 304; i ++){
		for(int j = 0; j < 304 ; j ++){
			if(map[i][j] > 0){
				found = 1;
				ans = min(ans, vis[i][j]);
			}
		}
	}
	if(found) printf("%d", ans + 1);
	else printf("-1");
	return 0;
}

bool cmpTime(loc a, loc b){
	return a.t < b.t;
}
