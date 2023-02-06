#include <cstdio>
#include <algorithm>
using namespace std;

typedef struct Meteor{
	int x, y, t;
} meteor;

int n, nowTime = 0, pos = 0;
int map[302][302] = {1};
meteor arr[50002];
int xx[5] = {0, 0, 1, 0, -1};
int yy[5] = {0, 1, 0, -1, 0};

bool cmpTime(meteor a, meteor b);

int main(){
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf("%d%d%d", &arr[i].x, &arr[i].y, &arr[i].t);
	}
	sort(arr, arr + n, cmpTime);
	while(1){
		while(arr[pos].t == nowTime){	//Update the map
			for(int i = 0; i < 5; i++){
				if(arr[pos].y + yy[i] >= 0 && arr[pos].x + xx[i] >= 0){
					map[arr[pos].y + yy[i]][arr[pos].x + xx[i]] = -1;
				}
			}
			pos ++;
		}
		for(int i = 0; i <= nowTime; i++){
			
		}
	}
	
}

bool cmpTime(meteor a, meteor b){
	if(a.t < b.t) return true;
	return false;
}
