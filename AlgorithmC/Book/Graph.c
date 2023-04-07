#include <stdio.h>
#include <stdlib.h>

#define INF 0x7fffffff
#define MAXN 100

typedef struct Graph{
	int vertex[MAXN];
	int edge[MAXN][MAXN];
	int numberOfEdge, numberOfVertex;
} Graph, *GraphP;

GraphP NewGraph();
void InitGraph(GraphP graph);
void InsertVertex(GraphP graph, int value);
void InsertEdge(GraphP graph, int v1, int v2, int weight, int mode);
void DeleteEdge(GraphP graph, int v1, int v2, int mode);
int Prim(GraphP graph, int* parents, int start);
void DFSGraph(GraphP graph, int now, int depth, int* visited);

int main(){
	GraphP a = NewGraph();
	for(int i = 0; i < 7; i++){
		InsertVertex(a, i);
	}
	InsertEdge(a, 0, 1, 1, 0);
	InsertEdge(a, 0, 2, 3, 0);
	InsertEdge(a, 0, 4, 5, 0);
	InsertEdge(a, 1, 3, 3, 0);
	InsertEdge(a, 1, 4, 4, 0);
	InsertEdge(a, 2, 3, 3, 0);
	InsertEdge(a, 2, 4, 1, 0);
	InsertEdge(a, 3, 5, 6, 0);
	InsertEdge(a, 4, 5, 4, 0);
	int parents[7];
	int i = Prim(a, parents, 0);
	printf("The End");


}

GraphP NewGraph(){
	GraphP ret = (GraphP)malloc(sizeof(Graph));
	InitGraph(ret);
	return ret;
}

void InitGraph(GraphP graph){
	graph->numberOfEdge = 0;
	graph->numberOfVertex = 0;
	for(int i = 0; i < MAXN; i++){
		graph->vertex[i] = -1;
		for(int j = 0; j < MAXN; j++){
			graph->edge[i][j] = INF;
		}
	}
}

void InsertVertex(GraphP graph, int value){
	if(graph->numberOfVertex < MAXN - 1)
		graph->vertex[graph->numberOfVertex++] = value;
	else printf("E: Invalid Argument!\n");
}

void InsertEdge(GraphP graph, int v1, int v2, int weight, int mode){
	//0 无向图， 1 有向图
	//v1 v2 指的是节点的值
	if(v1 < graph->numberOfVertex && v2 < graph->numberOfVertex && v1 >= 0 && v2 >= 0){
		graph->edge[v1][v2] = weight;
		if(!mode){
			graph->edge[v2][v1] = weight;
		}
	} else {
		printf("E: Invalid Argument!\n");
	}
}

void DeleteEdge(GraphP graph, int v1, int v2, int mode){
	if(v1 < graph->numberOfEdge && v2 < graph->numberOfVertex && v1 >= 0 && v2 >= 0){
		graph->edge[v1][v2] = INF;
		if(!mode) graph->edge[v2][v1] = INF;
	} else {
		printf("E: Invalid Argument!\n");
	}
}

int Prim(GraphP graph, int* parents, int start){
	int size = graph->numberOfVertex;
	int parent[size], dist[size], walked[size];
	int ans = 0;
	for(int i = 0; i < size; i++){
		parents[i] = -1;
		walked[i] = 0;
		parent[i] = -1;
		dist[i] = INF;
	}
	dist[start] = 0;
	parents[start] = -1;
	//寻找dist最少的
	for(int i = 0; i < size; i++){
		int minDist = INF;
		int need2Select = -1;
		for(int j = 0; j < size; j++){
			if(dist[j] < minDist && walked[j] == 0){
				need2Select = j;
				minDist = dist[j];
			}
		}
		if(need2Select == -1) break;
		walked[need2Select] = 1;
		ans += dist[need2Select];
		//更新列表
		for(int j = 0; j < size; j++){
			if(walked[j] == 0 && graph->edge[need2Select][j] != INF && graph->edge[need2Select][j] < dist[j]){
				dist[j] = graph->edge[need2Select][j];
				parents[j] = parent[j] = need2Select;
			}
		}
	}
	return ans;
}

void DFSGraph(GraphP graph, int now, int depth, int* visited){
	visited[now] = 1;
	printf("%d ", now);
	for(int i = 0; i < graph->numberOfVertex; i++){
		if(visited[i] == 0 && graph->edge[now][i] != INF){
			DFSGraph(graph, i, depth + 1, visited);
		}
	}
}

void Dijkstra(GraphP graph, int start, int* parents){
	int dist[graph->numberOfVertex], visited[graph->numberOfVertex];
	int ret = 0;
	for(int i = 0; i < graph->numberOfVertex; i++){
		dist[i] = INF;
		parents[i] = -1;
		visited[i] = 0;
	}
	dist[start] = 0;
	for(int i = 0; i < graph->numberOfVertex; i++){
		int min = INF, minLoc = -1;
		for(int j = 0; j < graph->numberOfVertex; j++){
			if(dist[j] < min && visited[j] == 0){
				min = dist[j];
				minLoc = j;
			}
		}
		if(minLoc == -1) return -1;
		visited[minLoc] = 1;
		for(int j = 0; j < graph->numberOfVertex; j++){
			if(visited[j] == 0 && graph->edge[minLoc][j] != INF && graph->edge[minLoc][j] + dist[minLoc] < dist[j]){
				
			}
		}
	}
}