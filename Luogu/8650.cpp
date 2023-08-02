#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

char str[110] = {'('};

int dfs(int l, int r);

int main(){
	cin >> &str[1];
	int len = strlen(str);
	str[len] = ')';
	cout << dfs(0, len);
	return 0;
}

int dfs(int l, int r){
	int now = l + 1;
	int ret = 0;
	int thisTime = 0;
	while(now <= r){
		if(str[now] == 'x'){
			thisTime++;
			now++;
		} else if(str[now] == '('){
			int temp = now;
			int brac = 1;
			now++;
			while(brac > 0){
				if(str[now] == '(') brac++;
				else if(str[now] == ')') brac--;
				now++;
			}
			thisTime += dfs(temp, now - 1);
		} else {
			ret = max(ret, thisTime);
			thisTime = 0;
			now++;
		}
		ret = max(ret, thisTime);
	}
	ret = max(ret, thisTime);
	return ret;
}
