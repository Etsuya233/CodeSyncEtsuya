#include <cstdio>
#include <algorithm>
using namespace std;

typedef struct row{
	int w, b, r;
} Row;

int main(){
	int n, m;
	scanf("%d%d", &n, &m);
	Row data[n];
	for(int i = 0 ; i < n; i++){
//		int w = 0, b = 0, r = 0;
		for(int j = 0; j < m; j++){
			char c;
			scanf("%c ", &c);
			if(c == 'W') data[i].w++;
			else if(c == 'R') data[i].b++;
			else data[i].r++;
		}
//		int maximun = max(w, max(b, r));
//		if(maximun == w) data[i] = 1;
//		else if(maximun == b) data[i] = 2;
//		else data[i] = 3;
	}
	
	int minimun = 0;
	int head = data[0].b + data[0].r + data[n - 1].w + data[n - 1].b;
	int cost_w = 0, cost_b = 0, cost_r = 0, cost = 0;
	for(int i = 0; i < n - 3; i++){
		cost = 0, cost_b = 0, cost_r = 0, cost_w = 0;
		for(int j = 0; j <= i; i++){
			cost_w += data[j].b + data[j].r;
		}
		for(int j = n - 1; j >= i + 2; j--){
			cost_r += data[j].b + data[j].w;
			for(int k = i + 1; k < j; k++){
				cost_b += data[j].r + data[j].r;
			}
			cost = cost_b + cost_r + cost_w;
			if(cost + head > minimun) minimun = cost + head;
		}
	}
	printf("%d", minimun);
	
	
	
	
	return 0;
}
