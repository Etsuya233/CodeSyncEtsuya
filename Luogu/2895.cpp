#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;

typedef struct Loc{
	int x, y, t;
} loc;

int n, nowTime = 0, win = 1, pos = 0;
int map[302][302] = {0};
int walked[302][302] = {0};
loc stone[50001];
queue<loc> my;
int xx[5] = {0, 0, 1, 0, -1};
int yy[5] = {0, 1, 0, -1, 0};

bool cmpTime(loc a, loc b);

int main(){
	loc zero = {.x = 0, .y = 0};
	my.push(zero);
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf("%d%d%d", &stone[i].x, &stone[i].y, &stone[i].t);
	}
	sort(stone, stone + n, cmpTime);
	while(1){
		while(stone[pos].t == nowTime){	//Update the map
			for(int i = 0; i < 5; i++){
				if(stone[pos].y + yy[i] >= 0 && stone[pos].x + xx[i] >= 0){
					map[stone[pos].y + yy[i]][stone[pos].x + xx[i]] = 1;
				}
			}
			pos ++;
		}
		
	}
	
}

bool cmpTime(loc a, loc b){
	if(a.t < b.t) return true;
	return false;
}
