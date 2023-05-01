#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

typedef struct Line{
	int starter;
	int ender;
	int length;
} line;

int n, m;
int map[502][502] = {0};
int iii[] = {0, 1, 0, -1};
int jjj[] = {-1, 0, 1, 0};
line road[502]; //0: starter, 1:amount
int cityCanWater = 0;

int bfs();
void printRoad();
bool cmpStarter(line i, line j);

int main(){
	scanf("%d%d", &n, &m);
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			int temp;
			scanf("%d", &map[i][j]);
		}
	}
	int res = bfs();
	if(res){
		//not ok
		printf("0\n");
		printf("%d", res);
	} else {
		//ok
		printf("1\n");
		sort(road, road + m, cmpStarter);
		int now = m - 1, loc = 0; //now: real  loc: array
//		printRoad();
		while(now > 0){
			res++;
			now = road[loc].starter - 1;
			int locMemo = loc;
			for(; loc < cityCanWater; loc ++){
				if(road[loc].ender == now){
					break;
				}
				if(road[loc].ender < now){
					loc = locMemo;
					now ++;
				}
			}
		}
		printf("%d", res);
	}
}

int bfs(){//need 2 be optimized
	int havewater[502] = {0};
	int canSendWater[502] = {0};
	queue<int> ii;
	queue<int> jj;
	for(int i = 0; i < m; i++){
		int walked[502][502] = {0};
		ii.push(n - 1);
		jj.push(i);
		walked[n - 1][i] = 1;
		while(!ii.empty()){
			int nowi = ii.front(), nowj = jj.front();
			if(nowi == 0){
				//i: lack water city, nowj: water origin
				road[nowj].length ++;
				if((i < road[nowj].starter && canSendWater[nowj] == 1) || canSendWater[nowj] == 0){
//					printf("%d->%d   %d\n", nowj, i, road[nowj].starter);
					road[nowj].starter = i;
				}
				road[nowj].ender = road[nowj].starter + road[nowj].length - 1;
				havewater[i] = 1;
				if(canSendWater[nowj] == 0){
					canSendWater[nowj] = 1;
					cityCanWater ++;
				}
			}
			ii.pop();
			jj.pop();
			for(int j = 0; j < 4; j++){
				int nexti = nowi + iii[j], nextj = nowj + jjj[j];
				if(nexti >= 0 && nexti < n && nextj >= 0 && nextj < m && walked[nexti][nextj] == 0 && map[nexti][nextj] > map[nowi][nowj]){
					walked[nexti][nextj] = 1;
					ii.push(nexti);
					jj.push(nextj);
				}
			}
		}
	}
	int cnt = 0;
	for(int i = 0; i < m; i++){
		if(havewater[i] == 0) cnt++;
	}
	return cnt;
}

bool cmpStarter(line a, line b){
	if(a.ender > b.ender) return true;
	else if(a.ender < b.ender) return false;
	else {
		if(a.starter < b.starter) return true;
		else return false;
	}
}

void printRoad(){
	for(int i = 0; i < cityCanWater; i++){
		for(int j = 0; j < m; j++){
			if(j >= road[i].starter && j <= road[i].ender) printf("_");
			else printf(".");
		}
		printf("\n");
	}
}