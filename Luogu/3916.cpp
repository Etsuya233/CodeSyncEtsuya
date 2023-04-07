#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
using namespace std;

vector<int> arr[100005];
int n, m;
int res[100005] = {0};
int visited[100005] = {0};

int dfs(int loc, int father);

int main(){
	cin >> n >> m;
	for(int i = 1; i <= m; i++){
		int x, y;
		cin >> x >> y;
		arr[x].push_back(y);
	}
	for(int i = 0; i < n; i++){
		if(res[i] == 0) dfs(i, -1);
	}
	// memset(visited, 0, sizeof(visited));
	// for(int i = 0; i < n; i++){
	// 	if(res[i] == 0) dfs(i, -1);
	// }
	// memset(visited, 0, sizeof(visited));
	// for(int i = 0; i < n; i++){
	// 	if(res[i] == 0) dfs(i, -1);
	// }
	// memset(visited, 0, sizeof(visited));
	// for(int i = 0; i < n; i++){
	// 	if(res[i] == 0) dfs(i, -1);
	// }
	// memset(visited, 0, sizeof(visited));
	// for(int i = 0; i < n; i++){
	// 	if(res[i] == 0) dfs(i, -1);
	// }
	for(int i = 1; i <= n; i++){
		if(res[i]) cout << res[i] << " ";
		else cout << i << " ";
	}
}

int dfs(int loc, int father){
	visited[loc]++;
	vector<int>::iterator it = arr[loc].begin();
	int maximum = -1;
	for(; it != arr[loc].end(); it++){
		if(visited[*it] < 50){
			int ret = dfs(*it, loc);
			maximum = max(maximum, ret);
		} else {
			int ret = res[ret];
			maximum = max(maximum, ret);
		}
	}
	return res[loc] = max(maximum, loc);
}