#include <iostream>
#include <vector>
#include <utility>
using namespace std;

int n, m, s;
vector<int> arr[500005];
int pa[500005][20];
int d[500005];
int vis[500005] = {0};

void generate(int now, int depth);
int lca(int a, int b);

int main(){
	cin >> n >> m >> s;
	for(int i = 1; i <= n - 1; i++){
		int a, b;
		cin >> a >> b;
		arr[a].push_back(b);
		arr[b].push_back(a);
	}
	//generate tree
	vis[s] = 1;
	pa[s][0] = s;
	generate(s, 0);
	//pa array
	for(int k = 1; k <= 19; k++){
		for(int i = 1; i <= n; i++){
			pa[i][k] = pa[pa[i][k - 1]][k - 1];
		}
	}
	//lca
	for(int i = 1; i <= m; i++){
		int a, b;
		cin >> a >> b;
//		cout << "ans: " << lca(a, b) << "\n";
		cout << lca(a, b) << "\n";
	}
	return 0;
}

void generate(int now, int depth){
	d[now] = depth;
	for(auto it = arr[now].begin(); it != arr[now].end(); ){
		int node = *it;
		if(vis[node]){
			it = arr[now].erase(it);
		} else {
			vis[node] = 1;
			pa[node][0] = now;
			generate(node, depth + 1);
		}
	}
}

int lca(int a, int b){
	if(d[a] > d[b]){
		swap(a, b);
	}
	//same depth
	for(int i = 19; i >= 0; i--){
		if(d[a] <= d[pa[b][i]]){
			b = pa[b][i];
		}
		if(a == b) return a;
	}
	//lca
	for(int i = 19; i >= 0; i--){
		if(pa[a][i] != pa[b][i]){
			a = pa[a][i];
			b = pa[b][i];
		}
	}
	return pa[a][0];
}
