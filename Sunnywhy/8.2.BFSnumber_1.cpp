#include <cstdio>
#include <queue>
using namespace std;

int n;
int numberHash[100001] = {0};

int bfs();

int main(){
	scanf("%d", &n);
	printf("%d", bfs());
	return 0;
}

int bfs(){
	queue<int> my;
	my.push(1);
	int step = 0;
	while(true){
		int len = (int)my.size();;
		for(int i = 0; i < len; i++){
			if(my.front() == n) return step;
			numberHash[my.front()] = 1;
			if(my.front() + 1 <= n && !numberHash[my.front() + 1]) my.push(my.front() + 1);
			if(my.front() * 2 <= n && !numberHash[my.front() * 2]) my.push(my.front() * 2);
			my.pop();
		}
		step++;
	}
}
