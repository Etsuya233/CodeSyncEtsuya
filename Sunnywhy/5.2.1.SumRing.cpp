#include <cstdio>
#include <queue>
using namespace std;

int main(){
	int n;
	scanf("%d", &n);
	queue<int> my;
	for(int i = 0; i < n; i++){
		int a;
		scanf("%d", &a);
		my.push(a);
	}
	
	while(my.size() != 1){
		int a = my.front();
		my.pop();
		int b = my.front();
		my.pop();
		my.push(a + b);
	}
	printf("%d", my.front());
	
}
