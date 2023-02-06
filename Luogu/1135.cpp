#include <cstdio>
#include <algorithm>
#include <queue>
#include <utility>
using namespace std;

int n, a, b;
int arr[202] = {0};
int walked[202] = {0};
int success = 0;
int minStep = 0x7fffffff;
queue<pair<int, int> > my;

void dfs(int f, int step);
void bfs(int f);

int main(){
	scanf("%d%d%d", &n, &a, &b);
	for(int i = 1; i <= n; i++){
		scanf("%d", &arr[i]);
	}
	bfs(a);
	if(!success) minStep = -1;
	printf("%d", minStep);
	return 0;
}

void dfs(int f, int step){
	if(f == b){
		success = 1;
		minStep = min(step, minStep);
		return;
	}
	walked[f] = 1;
	if(f - arr[f] >= 1){
		if(!walked[f - arr[f]]) dfs(f - arr[f], step + 1);
	}
	if(f + arr[f] <= n){
		if(!walked[f + arr[f]]) dfs(f + arr[f], step + 1);
	}
	walked[f] = 0;
}

void bfs(int f){
	my.push(make_pair(f, 0));
	walked[f] = 1;
	while(!my.empty()){
		if(my.front().first == b){
			success = 1;
			minStep = my.front().second;
			return;
		}
		int first = my.front().first;
		int second = my.front().second;
		if(!walked[first - arr[first]] && first - arr[first] >= 1){
			walked[first - arr[first]] = 1;
			my.push(make_pair(first - arr[first], second + 1));
		}
		if(!walked[first + arr[first]] && first + arr[first] <= n){
			walked[first + arr[first]] = 1;
			my.push(make_pair(first + arr[first], second + 1));
		}
		my.pop();
	}
}
