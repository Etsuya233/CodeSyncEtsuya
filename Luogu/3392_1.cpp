#include <cstdio>
#include <iostream>
using namespace std;

typedef struct row{
	int w, b, r;
	row(){
		w = b = r = 0;
	}
} Row;

int main(){
	int n, m;
	scanf("%d%d", &n, &m);
	Row data[n];
	getchar();
	for(int i = 0 ; i < n; i++){
		for(int j = 0; j < m; j++){
			char c;
//			scanf("%c", &c);
			cin >> c;
			if(c == 'W') data[i].w++;
			else if(c == 'R') data[i].r++;
			else data[i].b++;
		}
		getchar();
//		printf("%d: w = %d, b = %d, r = %d\n", i, data[i].w, data[i].b, data[i].r);
	}
	
//	printf("\n------\n");
	
	int cost = 0, minimun = 50000;
	int w = 0, b = 0, r = 0;
//	Algorithm
	for(int i = 0; i <= n - 3; i++){
		for(int j = n - 1; j >= i + 2; j--){
			w = 0, b = 0, r = 0;
			//Calc
			for(int k = 0; k <= i; k++){
				w += data[k].b + data[k].r;
			}
			for(int k = i + 1; k < j; k++){
				b += data[k].w + data[k].r;
			}
			for(int k = j; k <= n - 1; k++){
				r += data[k].w + data[k].b;
			}
//			printf("i = %d, j = %d, w = %d, b = %d, r = %d\n", i, j, w, b, r);
			cost = w + b + r;
//			printf("%d\n", cost);
			minimun = (cost < minimun)? cost: minimun;
		}
	}
	
	printf("%d", minimun);
}
