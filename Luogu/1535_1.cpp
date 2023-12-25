#include <iostream>
#include <queue>
#include <cmath>
using namespace std;

typedef struct Position{
	int i, j, t;
} po;

int ii[4] = {0, 1, 0, -1};
int jj[4] = {1, 0, -1, 0};
int n, m, t, cnt = 0;
int si, sj, di, dj;
char arr[205][205];

void bfs();

int main(){
	cin >> n >> m >> t;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			cin >> arr[i][j];
		}
	}
	cin >> si >> sj >> di >> dj;
	bfs();
	cout << cnt;
	return 0;
}

void bfs(){
	queue<po> qu;
	po now;
	po next;
	now.i = si;
	now.j = sj;
	now.t = 0;
	qu.push(now);
	while(!qu.empty()){
		now = qu.front();
		qu.pop();
		if(now.t == t){
			if(now.i == di && now.j == dj) cnt++;
			continue;
		}
		for(int i = 0; i < 4; i++){
			next.i = now.i + ii[i];
			next.j = now.j + jj[i];
			next.t = now.t + 1;
			if(next.i >= 1 && next.i <= n && next.j >= 1 && next.j <= m && arr[next.i][next.j] != '*' && t - next.t >= (abs(di - next.i) + abs(dj - next.j))){
				qu.push(next);
			}
		}
	}
}








