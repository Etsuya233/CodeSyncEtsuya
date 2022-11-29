#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std;

typedef struct room{
	int javabean;
	int catfood;
	int unit;
} room;

bool cmpUnit(room a, room b);

int main(){
	int	 M, N; //M->cat food  N->room
	while(1){
		cin >> M >> N;
		room warehouse[N];
		for(int i = 0; i < N; i++){
			cin >> warehouse[i].javabean >> warehouse[i].catfood;
			warehouse[i].unit = warehouse[i].javabean / warehouse[i].catfood;
		}
		
		sort(warehouse, warehouse + N, cmpUnit);
		
		double got = 0;
		for(int i = 0; i < N; i++){
			if(warehouse[i].catfood <= M){
				M -= warehouse[i].catfood;
				got += warehouse[i].javabean;
			}
			if(warehouse[i].catfood > M){
				got += warehouse[i].javabean * 1.0 * M / warehouse[i].catfood;
				break;
			}
		}
		printf("%.3f\n", got);
	}
}

bool cmpUnit(room a, room b){
	return a.unit > b.unit;
}
