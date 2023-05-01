#include <iostream>
#include <queue>
#include <algorithm>
//#include <windows.h>
using namespace std;

int n, m;
char direction;
int starti, startj, endi, endj;
int realmap[55][55] = {0};
int walked[55][55] = {0};

int ai[] = {0, 0, 1, 1};
int aj[] = {0, 1, 0, 1};

int bi[] = {-1, 0, 1, 0};
int bj[] = {0, 1, 0, -1};

int starter[100];

void printMap();

int main(){
	starter['N'] = 0;
	starter['E'] = 1;
	starter['S'] = 2;
	starter['W'] = 3;
	cin >> n >> m;
	for(int i = 0; i <= n + 2; i++){
		fill(walked[i], walked[i] + m + 2, 0x7fffffff);
	}
	//Process the map
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			int stone;
			cin >> stone;
			if(stone == 1){
				for(int k = 0; k < 4; k++){
					int reali = i + ai[k];
					int realj = j + aj[k];
					if(reali >= 0 && reali <= n && realj >= 0 && realj <= m){
						realmap[reali][realj] = 1;
					}
				}
			}
		}
	}
	cin >> starti >> startj >> endi >> endj >> direction;
	walked[starti][startj] = 0;
	if(starti == endi && startj == endj){
		cout << 0;
		return 0;
	}
	//Process the bfs
	queue<int> nowi;
	queue<int> nowj;
	queue<int> di;
	nowi.push(starti);
	nowj.push(startj);
	di.push(starter[direction]);
	while(!nowi.empty()){
		int i = nowi.front(), j = nowj.front(), d = di.front();
		nowi.pop();
		nowj.pop();
		di.pop();
		int nowdi = d;
		for(int cnt = 0; cnt < 4; cnt++){
			int k = 1;
			int increment;
			switch(cnt){
				case 0:
					increment = 1;
					break;
				case 1:
					increment = 2;
					break;
				case 2:
					increment = 3;
					break;
				case 3:
					increment = 2;
			}
			for(; k <= 3; k++){
				if(i + bi[nowdi] * k > 0 && i + bi[nowdi] * k < n && j + bj[nowdi] * k > 0 && j + bj[nowdi] * k < m){
					if(walked[i + bi[nowdi] * k][j + bj[nowdi] * k] < walked[i][j] + increment) continue; //need 2 correct
					if(realmap[i + bi[nowdi] * k][j + bj[nowdi] * k] == 1){
						break;
					}
					walked[i + bi[nowdi] * k][j + bj[nowdi] * k] = walked[i][j] + increment;
					nowi.push(i + bi[nowdi] * k);
					nowj.push(j + bj[nowdi] * k);
					di.push(nowdi);
				}
			}
			nowdi = (nowdi + 1) % 4;
		}
//		Sleep(500);
//		printMap();
//		cout << "\n";
//		cout << "!";
	}
//	printMap();
	if(walked[endi][endj] == 0x7fffffff) cout << -1;
	else cout << walked[endi][endj];
}

void printMap(){
	for(int i = 0; i <= n; i++){
		for(int j = 0; j <= m; j++){
			if(realmap[i][j] == 1){
				cout << "# ";
			} else if(walked[i][j] > 100 || walked[i][j] < -100){
				cout << "_ ";
			} else cout << walked[i][j] << " ";
		}
		cout << "\n";
	}
}