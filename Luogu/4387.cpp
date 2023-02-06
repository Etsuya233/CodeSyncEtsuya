#include <cstdio>
#include <stack>
using namespace std;



int main(){
	int n, m;
	int pushed[100000], popped[100000];
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf("%d", &m);
		for(int j = 0; j < m; j++){
			int num;
			scanf("%d", &num);
			pushed[j] = num;
		}
		for(int j = 0; j < m; j++){
			scanf("%d", &popped[j]);
		}
		int locPus = 0, locPop = 0, flag = 0;
		stack<int> my;
		while(true){
			if(my.empty() && locPop != m) my.push(pushed[locPus++]);
			else if(my.top() != popped[locPop] && locPus != m) my.push(pushed[locPus++]);
			else if(my.top() != popped[locPop] && locPus == m) break;
			else if(my.top() == popped[locPop]){
				my.pop();
				locPop ++;
				if(locPop == m){
					flag = 1;
					break;
				}
			}
		}
		if(flag) printf("Yes\n");
		else printf("No\n");
	}
}