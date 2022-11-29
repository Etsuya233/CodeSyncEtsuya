#include <cstdio>
#include <stack>
#include <cstring>
using namespace std;

int main(){
	int n;
	scanf("%d", &n);
	stack<int> my;
	for(int i = 0; i < n; i++){
		char operate[5];
		char pu[5] = "push";
		scanf("%s", operate);
		if(!strcmp(operate, pu)){
			int loc;
			scanf("%d", &loc);
			my.push(loc);
		} else {
			if(my.empty()){
				printf("-1\n");
			} else {
				printf("%d\n", my.top());
				my.pop();
			}
		}
	}
	return 0;
}
