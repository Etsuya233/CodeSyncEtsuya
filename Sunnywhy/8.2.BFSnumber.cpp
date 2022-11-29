#include <cstdio>
#include <queue>
using namespace std;

typedef struct layer{
	int number, step = 0;
} Layer;

int minStep = 1000000007;
int numberHash[100001] = {0};
int n;

void bfs();

int main(){
	scanf("%d", &n);
	bfs();
	printf("%d", minStep);
	return 0;
}

void bfs(){
	queue<Layer> my;
	Layer ret;
	ret.number = 1;
	my.push(ret);
	while(!my.empty()){
		if(my.front().number == n){
			minStep = my.front().step;
			return;
		}
		numberHash[my.front().number] = 1;
		if(my.front().number < n){
			ret.step = my.front().step + 1;
			ret.number = my.front().number + 1;
			my.push(ret);
			ret.number = my.front().number * 2;
			my.push(ret);
		}
		my.pop();
	}
}
