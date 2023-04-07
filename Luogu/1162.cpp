#include <iostream>
#include <queue>
using namespace std;

typedef struct Point{
	int map = 0;
	int tag = 0;
	int ansx = 0, ansy = 0;
} point;

point arr[33][33];
int n;
int xx[] = {0, 1, 0, -1};
int yy[] = {-1, 0, 1, 0};

void bfs(int x, int y);
void print(int x, int y);

int main(){
	cin >> n;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			cin >> arr[i][j].map;
		}
	}
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			if(arr[i][j].map == 0 && arr[i][j].tag == 0) bfs(j, i);
		}
	}
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			print(j, i);
			cout << " ";
		}
		cout << "\n";
	}
	
}

void bfs(int x, int y){
	if(arr[y][x].tag != 0) return;
	point temp = {
		.ansx = x,
		.ansy = y
	};
	queue<point> my;
	my.push(temp);
	int hasWall = 1;
	int nowx, nowy;
	arr[y][x].tag = 1;
	while(!my.empty()){
		for(int i = 0; i < 4; i++){
			if((nowx = my.front().ansx + xx[i]) >= 1 && nowx <= n && (nowy = my.front().ansy + yy[i]) >= 1 && nowy <= n && arr[nowy][nowx].map == 0){
				if(arr[nowy][nowx].tag == 0){
					temp.ansx = nowx;
					temp.ansy = nowy;
					my.push(temp);
					arr[nowy][nowx].tag = 2;
					arr[nowy][nowx].ansx = x;
					arr[nowy][nowx].ansy = y;
					//					cout << "Push " << nowy << " " << nowx << "\n";
				}
			} else if((nowx = my.front().ansx + xx[i]) >= 1 && nowx <= n && (nowy = my.front().ansy + yy[i]) >= 1 && nowy <= n && arr[nowy][nowx].map == 1 ){
				
			} else hasWall = 0;
		}
		my.pop();
	}
	arr[y][x].map = (hasWall)? 2: 0;
}

void print(int x, int y){
	if(arr[y][x].tag == 1){
		cout << arr[y][x].map;
	} else if(arr[y][x].tag == 2){
		print(arr[y][x].ansx, arr[y][x].ansy);
	} else {
		cout << "1";
	}
}
