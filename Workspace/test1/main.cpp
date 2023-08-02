#include <cstdio>
#include <cstdlib>
#include "Graph.h"
#define INF 0x7fffffff

int main(){
	char vertex[10] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j'};
	int edge[10][10] = {
			{1,INF,INF,INF,INF,1,2,INF,INF,0},
			{3,1,2,4,INF,INF,INF,INF,INF,0},
			{INF,INF,INF,INF,INF,INF,INF,INF,INF,1},
			{4,3,2,1,6,7,8,9,INF,0},
			{10,INF,INF,INF,INF,INF,INF,INF,INF,2},
			{INF,INF,INF,INF,INF,INF,INF,2,3,4},
			{1,2,5,3,8,INF,3,1,3,5},
			{2,INF,INF,INF,INF,INF,INF,INF,INF,0},
			{INF,INF,INF,INF,INF,1,INF,INF,INF,0},
			{3,2,5,7,1,INF,INF,INF,INF,7}
	};

	GraphM graph = GraphMCreateByArray(10, vertex, (int*)edge);
	GraphMPrint(graph);

}