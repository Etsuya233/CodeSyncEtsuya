#ifndef _GRAPH_H_
#define _GRAPH_H_

#include <stdio.h>
#include <stdlib.h>
#define MAXN 100
#define INF 0x7fffffff

typedef struct Graph{
	int vertex[MAXN];
	int edge[MAXN][MAXN];
	int numberOfEdge, numberOfVertex;
} Graph, *GraphP;

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

#endif