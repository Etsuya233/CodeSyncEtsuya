#include <cstdio>
#include <algorithm>
using namespace std;

int chizu[22][22] = {0};
long long storage[22][22] = {0};
int sum = 0;
void horse(int i, int j);
void horse2();

int n, m, x, y;

int main(){
	
	scanf("%d %d %d %d", &n, &m, &x, &y);
	
	//To find the horse's place
	x++, y++;
	chizu[x][y] = 1;
	if(x - 1 >= 1 && y - 2 >= 1) chizu[x - 1][y - 2] = 1;
	if(x + 1 <= n + 1 && y - 2 >= 1) chizu[x + 1][y - 2] = 1;
	if(x - 2 >= 1 && y - 1 >= 1) chizu[x - 2][y - 1] = 1;
	if(x + 2 <= n + 1 && y - 1 >= 1) chizu[x + 2][y - 1] = 1;
	if(x - 1 >= 1 && y + 2 <= m + 1) chizu[x - 1][y + 2] = 1;
	if(x + 1 <= n + 1 && y + 2 <= m + 1) chizu[x + 1][y + 2] = 1;
	if(x - 2 >= 1 && y + 1 <= m + 1) chizu[x - 2][y + 1] = 1;
	if(x + 2 <= n + 1 && y + 1 <= m + 1) chizu[x + 2][y + 1] = 1;
	
	horse2();
	printf("%lld", storage[n + 1][m + 1]);
	return 0;
	
}

void horse(int i, int j){
	if(i < 0 || j < 0) return;
	if(chizu[i][j]) return;
	if(i == 0 && j == 0){
		sum++;
		return;
	}
	horse(i - 1, j);
	horse(i, j - 1);
}

void horse2(){
	storage[0][1] = 1; 
	storage[1][0] = 0;
	for(int i = 0; i <= n; i++){
		for(int j = 0; j <= m; j++){
			if(chizu[i + 1][j + 1]) continue;	//To judge if there is a horse
			storage[i + 1][j + 1] = storage[i][j + 1] + storage[i + 1][j];
//			printf("%d %d -> %d\n", i + 1, j + 1, storage[i + 1][j + 1]);
		}
	}
}
