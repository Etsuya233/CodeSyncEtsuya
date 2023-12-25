#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

typedef struct Position{
	int i, j, d, t;//0 1 2 3 n e s w
} po;

int ii[4] = {-1, 0, 1, 0};
int jj[4] = {0, 1, 0, -1};
int n, m;
int si, sj, di, dj;
char d;
int mapa[55][55] = {0};
int vis[55][55][4] = {0};
po tempa;

int bfs();

int main(){
	cin >> n >> m;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			int tempo;
			cin >> tempo;
			if(tempo == 1){
				mapa[i][j] = 1;
				mapa[i + 1][j] = 1;
				mapa[i][j + 1] = 1;
				mapa[i + 1][j + 1] = 1;
			}
		}
	}
	cin >> si >> sj >> di >> dj >> d;
	tempa.i = si;
	tempa.j = sj;
	tempa.t = 0;
	if(d == 'N') tempa.d = 0;
	else if(d == 'E') tempa.d = 1;
	else if(d == 'S') tempa.d = 2;
	else tempa.d = 3;
	int ans = bfs();
	cout << ans;
	return 0;
}

int bfs(){
	fill(vis[0][0], vis[0][0] + 55 * 55 * 4, 0x3fffffff);
	queue<po> qu;
	qu.push(tempa);
	po now;
	po next;
	while(!qu.empty()){
		now = qu.front();
		qu.pop();
		cout << now.i << " " << now.j << " " << now.d << " " << now.t << "\n";
		if(now.i == di && now.j == dj){
			return now.t;
		}
		vis[now.i][now.j][now.d] = now.t;
		next.t = now.t + 1;
		//front * 3
		next.i = now.i + ii[now.d];
		next.j = now.j + jj[now.d];
		next.d = now.d;
		if(next.i > 0 && next.i < n && next.j > 0 && next.j < m && !mapa[next.i][next.j] && next.t < vis[next.i][next.j][next.d]){
			qu.push(next);
			vis[next.i][next.j][next.d] = next.t;
			next.i = next.i + ii[next.d];
			next.j = next.j + jj[next.d];
			next.d = next.d;
			if(next.i > 0 && next.i < n && next.j > 0 && next.j < m && !mapa[next.i][next.j] && next.t < vis[next.i][next.j][next.d]){
				qu.push(next);
				vis[next.i][next.j][next.d] = next.t;
				next.i = next.i + ii[next.d];
				next.j = next.j + jj[next.d];
				next.d = next.d;
				if(next.i > 0 && next.i < n && next.j > 0 && next.j < m && !mapa[next.i][next.j] && next.t < vis[next.i][next.j][next.d]){
					qu.push(next);
					vis[next.i][next.j][next.d] = next.t;
				}
			}
		}
		//left
		next.i = now.i;
		next.j = now.j;
		next.d = (4 + now.d + 1) % 4;
		if(next.i > 0 && next.i < n && next.j > 0 && next.j < m && !mapa[next.i][next.j] && next.t < vis[next.i][next.j][next.d]){
			qu.push(next);
			vis[next.i][next.j][next.d] = next.t;
		}
		//right
		next.i = now.i;
		next.j = now.j;
		next.d = (now.d - 1 + 4) % 4;
		if(next.i > 0 && next.i < n && next.j > 0 && next.j < m && !mapa[next.i][next.j] && next.t < vis[next.i][next.j][next.d]){
			qu.push(next);
			vis[next.i][next.j][next.d] = next.t;
		}
	}
	return -1;
}












