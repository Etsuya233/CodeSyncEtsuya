#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define INF 0x3fffffff

typedef struct GraphNode{
	int next, dis;
} node;

int d[1005] = {0};
vector<node> arr[1005];
int vertexOfMap = 15;
bool vis[1005] = {false};
int dd[1005][1005] = {0};

int main(){
	
}

void dijkstra(int start){ //最短路算法，此时d数组的意义是顶点i到起点start的最短距离
	fill(d, d + 1005, INF);
	d[start] = 0;
	for(int i = 0; i < vertexOfMap; i++){
		int u = -1, minDis = INF;
		for(int j = 0; j < vertexOfMap; j++){
			if(vis[j] == false && d[j] < minDis){
				minDis = d[j];
				u = j;
			}
		}
		if(u == -1) return;
		vis[u] = true;
		//更新距离
		for(int j = 0; j < arr[u].size(); j++){
			int next = arr[u][j].next;
			if(vis[next] == false && d[u] + arr[u][j].dis < d[next]){
				d[next] = d[u] + arr[u][j].dis;
			}
		}
	}
}

void floyd(int start){ //全源最短路，此时d数组的意义是顶点i到起顶点j的最短距离，推荐使用邻接矩阵
	fill(dd, dd + 1005 * 1005, INF);
	for(int i = 0; i < vertexOfMap; i++){ //如果有邻接矩阵，这一步就不用，这一步是把邻接链表所有的路径全部都复制到dd中
		for(int j = 0; j < arr[i].size(); j++){
			int next = arr[i][k].next;
			dd[i][next] = arr[i][k].dis;
		}
	}
	for(int i = 0; i < vertexOfMap; i++){
		for(int j = 0; j < vertexOfMap; j++){
			for(int k = 0; k < arr[i].size(); k++){
				int next = arr[i][k].next;
				if(dd[i][next] != INF && dd[next][j] != INF && dd[i][next] + dd[next][j] < dd[i][j]){
					dd[i][j] = dd[i][next] + dd[next][j];
				}
			}
		}
	}
}

void prim(int start){ //最小生成树，此时d数组的意义是顶点i到已确定树的集合的最短距离
	fill(d, d + 1005, INF);
	d[start] = 0;
	for(int i = 0; i < vertexOfMap; i++){
		int u = -1, minDis = INF;
		for(int j = 0; j < vertexOfMap; j++){
			if(vis[j] == false && d[j] < minDis){
				minDis = d[j];
				u = j;
			}
		}
		if(u == -1) return;
		vis[u] = true;
		//更新距离
		for(int j = 0; j < arr[u].size(); j++){
			int next = arr[u][j].next;
			if(vis[next] == false && arr[u][j].dis < d[next]){
				d[next] = arr[u][j].dis;
			}
		}
	}
}
