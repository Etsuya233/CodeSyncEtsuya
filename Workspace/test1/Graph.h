//
// Created by etsuy on 2023/5/11.
//

#ifndef TEST1_GRAPH_H
#define TEST1_GRAPH_H

#include <cstdio>
#include <cstdlib>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

#define MAX_VERTEX_NUM 100
#define INF 0x7fffffff

typedef struct GraphMatrix{
	char vertex[MAX_VERTEX_NUM]{0};
	int edge[MAX_VERTEX_NUM][MAX_VERTEX_NUM];
	int vertexNum = 0;
	int edgeNum = 0;
} GraphMN, *GraphM;

GraphM GraphMCreate(){
	GraphM graph = (GraphM)malloc(sizeof(GraphMN));
	fill(graph->edge[0], graph->edge[0] + MAX_VERTEX_NUM * MAX_VERTEX_NUM, INF);
	graph->vertexNum = 0;
	graph->edgeNum = 0;
	return graph;
}

GraphM GraphMCreateByArray(int vertexNum, const char vertex[], const int* edge){
	GraphM graph = (GraphM)malloc(sizeof(GraphMN));
	graph->vertexNum = vertexNum;
	graph->edgeNum = 0;
	for(int i = 0; i < vertexNum; i++){
		graph->vertex[i] = vertex[i];
		for(int j = 0; j < vertexNum; j++){
			if(edge[i * vertexNum + j] != INF){
				graph->edgeNum++;
				graph->edge[i][j] = edge[i * vertexNum + j];
			}
		}
	}
	return graph;
}

void GraphMPrint(const GraphM graph){
	printf("GraphMatrix %p:\n", graph);
	printf("Vertex: ");
	for(int i = 0; i < graph->vertexNum; i++){
		printf("%c ", graph->vertex[i]);
	}
	printf("\n");
	printf("Edge: \n");
	for(int i = 0; i < graph->vertexNum; i++){
		for(int j = 0; j < graph->vertexNum; j++){
			if(graph->edge[i][j] != INF){
				printf("%d ", graph->edge[i][j]);
			}else{
				printf("INF ");
			}
		}
		printf("\n");
	}
}

#endif //TEST1_GRAPH_H
