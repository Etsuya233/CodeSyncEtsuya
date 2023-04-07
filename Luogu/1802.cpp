#include <iostream>
using namespace std;

typedef struct People{
	int lose, win, use;
} pp;

int n, x, ans = 0;
pp arr[1001];

void dfs(int i, int exp, int left);

int main(){
	cin >> n >> x;
	for(int i = 1; i <= n; i++) cin >> arr[i].lose >> arr[i].win >> arr[i].use;
	dfs(1, 0, x);
	cout << ans * 5;
}

void dfs(int i, int exp, int left){
	if(i > n){
		ans = max(ans, exp);
		return;
	}
	if(left >= arr[i].use){
		dfs(i + 1, exp + arr[i].win, left - arr[i].use);
		dfs(i + 1, exp + arr[i].lose, left);
	} else {
		dfs(i + 1, exp + arr[i].lose, left);
	}
}