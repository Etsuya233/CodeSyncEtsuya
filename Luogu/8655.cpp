#include <iostream>
using namespace std;

int n;
int parents[100005];

int uf_union(int p, int q);
int uf_connected(int p, int q);
int uf_find(int x);

int main(){
	cin >> n;
	for(int i = 0; i <= n; i++){
		parents[i] = i;
	}
	for(int i = 0; i < n; i++){
		int a, b;
		cin >> a >> b;

	}
	
}

// 1 连接成功 0 已存在连接
int uf_union(int p, int q){
	int rootP = find(p), rootQ = find(Q);
	if(rootP == rootQ) return 0;
	parents[rootQ] = rootP;
	return 1;
}

int uf_connected(int p, int q){
	int rootP = find(p), rootQ = find(Q);
	if(rootP == rootQ) return 1;
	return 0;
}

int uf_find(int x){
	if(parents[x] != x){
		parents[x] = uf_find(parents[x]);
	}
	return parents[x];
}
