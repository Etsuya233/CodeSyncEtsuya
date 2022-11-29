#include <cstdio>
#include <algorithm>
using namespace std;

int chizu[21][21] = {0};
int res[22][22] = {0};
long long sum = 0;
void horse(int i, int j);
long long C(int n, int m);

int n, m, x, y;
int borderx = 0, bordery = 0;

int main(){
	
	scanf("%d %d %d %d", &n, &m, &x, &y);
	
	//To find the horse's place
	chizu[x][y] = 1;
	if(x - 1 >= 0 && y - 2 >= 0) chizu[x - 1][y - 2] = 1;
	if(x + 1 <= n && y - 2 >= 0) chizu[x + 1][y - 2] = 1;
	if(x - 2 >= 0 && y - 1 >= 0) chizu[x - 2][y - 1] = 1;
	if(x + 2 <= n && y - 1 >= 0) chizu[x + 2][y - 1] = 1;
	if(x - 1 >= 0 && y + 2 <= m) chizu[x - 1][y + 2] = 1;
	if(x + 1 <= n && y + 2 <= m) chizu[x + 1][y + 2] = 1;
	if(x - 2 >= 0 && y + 1 <= m) chizu[x - 2][y + 1] = 1;
	if(x + 2 <= n && y + 1 <= m) chizu[x + 2][y + 1] = 1;
	
	if(x - 1 >= 0) borderx = x - 1;
	if(x - 2 >= 0) borderx = x - 2;
	if(y - 1 >= 0) bordery = y - 1;
	if(y - 2 >= 0) bordery = y - 2;
	
	horse(n, m);
	printf("%lld", sum);
	return 0;
	
}

void horse(int i, int j){
	if(i < 0 || j < 0) return;
	if(chizu[i][j]) return;
	if(i <= borderx && j <= bordery){
		int maximun = max(i, j);
		int minimun = min(i, j);
		sum += C(maximun + 1, minimun);
		i = -1, j = -1;
		return;
	} else {
		horse(i - 1, j);
		horse(i, j - 1);	
	}
}

long long C(int n, int m){
	if(m == 0 || m == n) return 1;
	if(res[n][m]) return res[n][m];
	return res[n][m] = C(n - 1, m) + C(n, m - 1);
}
