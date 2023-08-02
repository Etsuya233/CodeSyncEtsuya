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

typedef struct GraphListNode{
	int index, weight;
} GraphLNode, *GraphLN;

typedef struct GraphList{
	char vertex[MAX_VERTEX_NUM]{0};
	vector<GraphLNode> edge[MAX_VERTEX_NUM];
	int vertexNum = 0;
	int edgeNum = 0;
} GraphN, *Graph;

GraphM GraphMCreate(){
	GraphM graph = (GraphM)malloc(sizeof(GraphMN));
	fill(graph->edge[0], graph->edge[0] + MAX_VERTEX_NUM * MAX_VERTEX_NUM, INF);
	graph->vertexNum = 0;
	graph->edgeNum = 0;
	return graph;
}

GraphM GraphMCreateByArray(int vertexNum, const char vertex[], const int* edge){
	GraphM graph = GraphMCreate();
	graph->vertexNum = vertexNum;
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

Graph GraphCreate(){
	Graph ret = new GraphN;
	ret->vertexNum = 0;
	ret->edgeNum = 0;
	return ret;
}

int GraphLocateIndex(Graph graph, char data){
	for(int i = 0; i < graph->vertexNum; i++){
		if(graph->vertex[i] == data){
			return i;
		}
	}
	return -1;
}

Graph GraphCreateByArray(int vertexNum, const char vertex[], const int* edge){
	Graph graph = GraphCreate();
	for(int i = 0; i < vertexNum; i++){
		graph->vertex[i] = vertex[i];
		graph->vertexNum++;
	}
	GraphListNode temp;
	for(int i = 0; i < vertexNum; i++){
		for(int j = 0; j < vertexNum; j++){
			if(edge[i * vertexNum + j] != INF){
				temp.index = j;
				temp.weight = edge[i * vertexNum + j];
				graph->edge[i].push_back(temp);
				temp.index = i;
				graph->edge[j].push_back(temp);
				graph->edgeNum++;
			}
		}
	}
	return graph;
}

void GraphPrint(Graph graph){
	printf("Graph %p:\n", graph);
	printf("Vertex: ");
	for(int i = 0; i < graph->vertexNum; i++){
		printf("%c ", graph->vertex[i]);
	}
	printf("\n");
	printf("Edge: \n");
	for(int i = 0; i < graph->vertexNum; i++){
		printf("%c: ", graph->vertex[i]);
		for(int j = 0; j < graph->edge[i].size(); j++){
			printf("%d ", graph->edge[i][j]);
		}
		printf("\n");
	}
}

void GraphMBFS(GraphM graph){
	queue<int> q;
	int visited[MAX_VERTEX_NUM]{0};
	for(int i = 0; i < graph->vertexNum; i++){
		if(!visited[i]){
			q.push(i);
			visited[i] = 1;
			while(!q.empty()){
				int front = q.front();
				q.pop();
				printf("%c ", graph->vertex[front]);
				for(int j = 0; j < graph->vertexNum; j++){
					if(graph->edge[front][j] != INF && !visited[j]){
						q.push(j);
						visited[j] = 1;
					}
				}
			}
		}
	}
}

void GraphMDFSCore(GraphM graph, int now, int* visited){
	printf("%c ", graph->vertex[now]);
	visited[now] = 1;
	for(int i = 0; i < graph->vertexNum; i++){
		if(!visited[i] && graph->edge[now][i] != INF){
			GraphMDFSCore(graph, i, visited);
		}
	}
}

void GraphMDFS(GraphM graph){
	int visited[MAX_VERTEX_NUM]{0};
	for(int i = 0; i < graph->vertexNum; i++){
		if(!visited[i]) GraphMDFSCore(graph, i, visited);
	}
}

void GraphBFS(Graph graph){
	queue<int> q;
	int visited[MAX_VERTEX_NUM]{0};
	for(int i = 0; i < graph->vertexNum; i++){
		if(!visited[i]){
			q.push(i);
			visited[i] = 1;
			while(!q.empty()){
				int front = q.front();
				q.pop();
				printf("%c ", graph->vertex[front]);
				for(int j = 0; j < graph->edge[front].size(); j++){
					if(!visited[graph->edge[front][j].index]){
						q.push(graph->edge[front][j].index);
						visited[graph->edge[front][j].index] = 1;
					}
				}
			}
		}
	}
}

void GraphDFSCore(Graph graph, int now, int* visited){
	printf("%c ", graph->vertex[now]);
	visited[now] = 1;
	for(int i = 0; i < graph->edge[now].size(); i++){
		if(!visited[graph->edge[now][i].index]){
			GraphDFSCore(graph, graph->edge[now][i].index, visited);
		}
	}
}

void GraphDFS(Graph graph){
	int visited[MAX_VERTEX_NUM]{0};
	for(int i = 0; i < graph->vertexNum; i++){
		if(!visited[i]) GraphDFSCore(graph, i, visited);
	}
}


#endif //TEST1_GRAPH_H