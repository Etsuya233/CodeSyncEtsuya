#include <cstdio>
#include <stack>
#include <cstring>
using namespace std;

int main(){
	stack<int> number;
	char fomular[101];
	fgets(fomular, 100, stdin);
	for(int i = 0; i < (int)strlen(fomular) - 1; i += 2){
		if(fomular[i] >= '0' && fomular[i] <= '9') number.push(fomular[i] - '0');
		else {
			int a = number.top();
			number.pop();
			int b = number.top();
			number.pop();
			if(fomular[i] == '+') number.push(b + a);
			else number.push(b - a);
		}
	}
	printf("%d", number.top());
	return 0;
}
