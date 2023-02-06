#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

int n;
int food[11][2] = {0};
int used[11] = {0};
int ans = 0x7fffffff;

void dfs(int sour, int bitter, int sum, int pos);

int main(){
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf("%d%d", &food[i][0], &food[i][1]);
	}
	dfs(1, 0, 0, 0);
	printf("%d", ans);
	return 0;
}

void dfs(int sour, int bitter, int sum, int pos){
	if(pos == n){
		if(sum > 0) ans = min(abs(sour - bitter), ans);
		return;
	}
	dfs(sour * food[pos][0], bitter + food[pos][1], sum + 1, pos + 1);
	dfs(sour, bitter, sum, pos + 1);
}
