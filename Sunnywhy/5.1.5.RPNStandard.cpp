#include <cstdio>
#include <stack>
#include <cstring>
#include <map>
using namespace std;

int main(){
	char fomular[101];
	fgets(fomular, 100, stdin);
	stack<char> opera;
	char ret[150];
	int loc = 0;
	
	map<char, int> op;
	op['+'] = 1;
	op['-'] = 1;
	op['*'] = 2;
	op['/'] = 2;
	
	for(int i = 0; i < (int)strlen(fomular); i++){
		char now = fomular[i];
		if(now >= '0' && now <= '9'){
			ret[loc++] = now;
		} else if(now == '('){
			opera.push(now);
		} else if(now == ')'){
			do{
				ret[loc++] = opera.top();
				opera.pop();
			} while(opera.top() == '(');
		} else {
			if(opera.empty() || opera.top() == '('){
				opera.push(now);
			} else {
				if(op[now] > op[opera.top()]){
					opera.push(now);
				} else {
					while(op[now] <= op[opera.top()] && !opera.empty()){
						ret[loc++] = opera.top();
						opera.pop();
					}
					opera.push(now);
				}
			}
		}
	}
	while(!opera.empty()){
		ret[loc++] = opera.top();
		opera.pop();
	}
	ret[loc] = '\0';
	printf("%s", ret);
	
	
	return 0;
}
