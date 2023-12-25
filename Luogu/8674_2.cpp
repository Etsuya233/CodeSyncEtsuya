#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <queue>
#include <utility>
using namespace std;

int d[100050];
int vis[100050];
int n, k;
vector<int> arr[1000050];
priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> >> qu;

void dijkstra(int start);

int main(){
	cin >> n >> k;
	for(int i = 0; i <= n - 1; i++){
		arr[i].push_back((i + 1) % n);
		arr[i].push_back((i + k) % n);
	}
	fill(d, d + n, 0x3fffffff);
	dijkstra(0);
	int ans = -1;
	for(int i = 0; i < n; i++){
		ans = max(ans, d[i]);
	}
	cout << ans;
}

void dijkstra(int start){
	int now;
	int nowDis;
	d[start] = 0;
	qu.push(make_pair(0, 0));
	for(int pp = 0; pp < n; pp++){
		//find dmin
		nowDis = qu.top().first;
		now = qu.top().second;
		qu.pop();
		//traverse
		for(int i = 0; i < 2; i++){
			if(!vis[arr[now][i]] && d[now] + 1 < d[arr[now][i]]){
				d[arr[now][i]] = d[now] + 1;
				qu.push(make_pair(d[arr[now][i]], arr[now][i]));
			}
		}
	}
}
