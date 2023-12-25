#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int parents[100005];
bool vis[100005] = {false};
vector<vector<int> > edge;
int n;

void dfs(int op, int ed, vector<int> path);
int uf_union(int a, int b);
int find(int a);
int connected(int a, int b);

int main(){
	cin >> n;
	edge.resize(n + 1);
	for(int i = 0; i <= n; i++){
		parents[i] = i;
	}
	for(int i = 0; i < n; i++){
		int a, b;
		cin >> a >> b;
		edge[a].push_back(b);
		edge[b].push_back(a);
		if(connected(a, b)){
			vector<int> path;
			path.push_back(a);
			dfs(a, b, path);
			return 0;
		}
		uf_union(a, b);
	}
	return 0;
}

void dfs(int op, int ed, vector<int> path){
	vis[op] = 1;
	if(op == ed){
		sort(path.begin(), path.end());
		for(int i = 0; i < path.size(); i++){
			cout << path[i] << " ";
		}
		return;
	} else {
		for(int a: edge[op]){
			if(!vis[a]){
				vector<int> p = path;
				p.push_back(a);
				dfs(a, ed, p);
			}
		}
	}
}

int uf_union(int a, int b){
	int rootA = find(a);
	int rootB = find(b);
	if(rootA == rootB){
		return 0;
	} else {
		parents[rootB] = rootA;
		return 1;
	}
}

int find(int a){
	if(parents[a] == a) return a;
	return parents[a] = find(parents[a]);
}

int connected(int a, int b){
	return find(a) == find(b);
}
