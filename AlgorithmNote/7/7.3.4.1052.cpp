#include <cstdio>
#include <algorithm>
using namespace std;

typedef struct node{
	int adress;
	int flag = 0;
	int nex;
	int data;
} Node;

int main(){
	int n, start;
	scanf("%d %d", &n, &start);
	Node arr[10000];
	for(int i = 0; i < n; i++){
		int p, pnext, data;
		scanf("%d%d%d", &p, &pnext, &data);
		arr[p].nex = pnext;
		arr[p].adress = p;
		arr[p].data = data;
	}
	//Initialize
	for(int i = start; i != -1; i = arr[i].nex){
		arr[i].flag = 1;
	}
	//Sort the adress of nodes
	
	
}

bool cmpAdresa(Node a, Node b){
	if(a.flag && b.flag){
		if(a.adress > b.adress) return true;
		return false;
	} else {
		if(a.flag) return true;
		else return true;
	}
}
