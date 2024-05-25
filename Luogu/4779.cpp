#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

typedef pair<int, int> pii;

int n, m, s;
vector<pii> arr[100005];
int vis[100005] = {0};
int d[100005] = {0};

void dijkstra();

int main(){
	cin >> n >> m >> s;
	for(int i = 1; i <= m; i++){
		int a, b, c;
		cin >> a >> b >> c;
		arr[a].push_back({c, b});
//		arr[b].push_back({c, a});
	}
	dijkstra();
	for(int i = 1; i <= n; i++){
		cout << d[i] << " ";
	}
	return 0;
}

void dijkstra(){
	fill(d, d + n + 1, 0x3fffffff);
	priority_queue<pii, vector<pii>, greater<pii>> qu;
	qu.push({0, s});
	d[s] = 0;
	while(!qu.empty()){
		int dis = qu.top().first;
		int now = qu.top().second;
		qu.pop();
		if(vis[now]) continue;
		vis[now] = 1;
		for(pii next: arr[now]){
			int nextNode = next.second;
			int nextDis = next.first;
			if(!vis[nextNode] && dis + nextDis < d[nextNode]){
				d[nextNode] = dis + nextDis;
				qu.push({d[nextNode], nextNode});
			}
		}
	}
}
