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

void dijkstra(int start){ //���·�㷨����ʱd����������Ƕ���i�����start����̾���
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
		//���¾���
		for(int j = 0; j < arr[u].size(); j++){
			int next = arr[u][j].next;
			if(vis[next] == false && d[u] + arr[u][j].dis < d[next]){
				d[next] = d[u] + arr[u][j].dis;
			}
		}
	}
}

void floyd(int start){ //ȫԴ���·����ʱd����������Ƕ���i���𶥵�j����̾��룬�Ƽ�ʹ���ڽӾ���
	fill(dd, dd + 1005 * 1005, INF);
	for(int i = 0; i < vertexOfMap; i++){ //������ڽӾ�����һ���Ͳ��ã���һ���ǰ��ڽ��������е�·��ȫ�������Ƶ�dd��
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

void prim(int start){ //��С����������ʱd����������Ƕ���i����ȷ�����ļ��ϵ���̾���
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
		//���¾���
		for(int j = 0; j < arr[u].size(); j++){
			int next = arr[u][j].next;
			if(vis[next] == false && arr[u][j].dis < d[next]){
				d[next] = arr[u][j].dis;
			}
		}
	}
}
