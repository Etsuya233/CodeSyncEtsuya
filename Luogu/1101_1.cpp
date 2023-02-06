#include <cstdio>
#include <queue>
using namespace std;

typedef struct Coordinate{
	int x, y, type, pos;
} loc;

int main(){
	int n;
	char arr[202][202] = {""};
	char ans[202][202] = {""};
	char key[] = "yizhong";
	int xx[] = {0, 1, 1, 1, 0, -1, -1, -1};
	int yy[] = {-1, -1, 0, 1, 1, 1, 0, -1};
	scanf("%d", &n);
	for(int i = 0; i < n; i++) scanf("%s", arr[i]);
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			if(arr[i][j] == 'y'){
				queue<loc> my;
				for(int k = 0; k <= 7; k++){
					loc temp = {.x = j, .y = i, .type = k, .pos = 0};
					my.push(temp);
				}
				while(!my.empty()){
					loc temp = my.front();
					my.pop();
					if(arr[temp.y][temp.x] == key[temp.pos]){
						if(temp.pos == 6){	//represent it was yizhong
							int xxx = j, yyy = i;
							ans[yyy][xxx] = 'y';
							for(int k = 1; k <= 6; k++){
								ans[yyy += yy[temp.type]][xxx += xx[temp.type]] = key[k];
							}
							continue;
						}
						if(temp.x + xx[temp.type] >= 0 && temp.x + xx[temp.type] <= n - 1 && temp.y + yy[temp.type] >= 0 && temp.y + yy[temp.type] <= n - 1){
							loc temp1 = {.x = temp.x + xx[temp.type], .y = temp.y + yy[temp.type], .type = temp.type, .pos = temp.pos + 1};
							my.push(temp1);
						}
					}
				}
			}
		}
	}
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			if(ans[i][j] == '\0') printf("*");
			else printf("%c", ans[i][j]);
		}
		printf("\n");
	}
}
