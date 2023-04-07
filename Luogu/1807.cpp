#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef struct Edge{
	int next, weight;
} Edge;

int n, m;
vector<Edge> arr[1502];
int walked[1502] = {0};
int dist[1502] = {0};
Edge temp;

void bfs();

int main(){
	cin >> n >> m;
	for(int i = 1; i <= m; i++){
		int x, y, z;
		cin >> x >> y >> z;
		temp.next = y;
		temp.weight = z;
		arr[x].push_back(temp);
	}
	bfs();
	if(walked[n]) cout << dist[n];
	else cout << -1;
}

void bfs(){
	queue<int> my;
	my.push(1);
	dist[1] = 0;
	walked[1] = 1;
	vector<Edge>::iterator it;
	while (!my.empty()){
		for(it = arr[my.front()].begin(); it != arr[my.front()].end(); it++){
			if(walked[(*it).next] == 0 || dist[(*it).next] < dist[my.front()] + (*it).weight){
				walked[(*it).next] = 1;
				dist[(*it).next] = dist[my.front()] + (*it).weight;
				my.push((*it).next);
			}
		}    
		my.pop();
	}
}