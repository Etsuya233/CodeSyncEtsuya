#include <cstdio>
#include <queue>
using namespace std;

int main(){
	int n, k;
	scanf("%d%d", &n, &k);
	queue<int> my;
	for(int i = 1; i <= n; i++) my.push(i);
	int r = 1;
	while(my.size() != 1){
		if(r % k == 0){
			printf("%d ", my.front());
			my.pop();
			r = 1;
		} else {
			int a = my.front();
			my.pop();
			my.push(a);
			r++;
		}
	}
	printf("%d", my.front());	
	
	
}
