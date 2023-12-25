#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

typedef struct FuckingNode{
	int a, b, c;
} node;

int parent[1000007];
int exist[1000007];
int book[1000007 * 3];
int n, cnt = 0;
node nodes[100050];

int find(int i);
void u(int i, int j);
int connected(int i, int j);
bool cmpE(node a, node b);

int main(){
	cin >> n;
	for(int i = 0; i < n; i++){
		memset(exist, 0, sizeof(exist));
		int line;
		bool status = true;
		cin >> line;
		for(int j = 0; j < line; j++){
			cin >> nodes[j].a >> nodes[j].b >> nodes[j].c;
			book[cnt++] = nodes[j].a;
			book[cnt++] = nodes[j].b;
		}
		//¿Î…¢ªØ
		sort(book, book + cnt);
		int reu = unique(book, book + cnt) - book;
		for(int i = 0; i < n; i++){
			nodes[i].a = lower_bound(book, book + reu, nodes[i].a) - book;
			nodes[i].b = lower_bound(book, book + reu, nodes[i].b) - book;
		}
		
		sort(nodes, nodes + line, cmpE);
		for(int j = 0; j <= reu; j++){
			parent[i] = i;
		}
		for(int j = 0; j < line; j++){
			if(status){
				if(exist[nodes[j].a] && exist[nodes[j].b]){
					if(nodes[j].c != connected(nodes[j].a, nodes[j].b)) status = false;
				} else {
					if(!exist[nodes[j].a]) exist[nodes[j].b] = 1;
					if(!exist[nodes[j].a]) exist[nodes[j].b] = 1;
					u(nodes[j].a, nodes[j].b);
				}
			}
		}
		if(status) cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}

int find(int i){
	if(parent[i] != i){
		parent[i] = find(parent[i]);
	}
	return parent[i];
}

void u(int i, int j){
	int rootI = find(i);
	int rootJ = find(j);
	if(rootI == rootJ) return;
	parent[j] = i;
}

int connected(int i, int j){
	if(find(i) == find(j)) return 1;
	else return 0;
}

bool cmpE(node a, node b){
	if(a.c < b.c) return true;
	return false;
}
