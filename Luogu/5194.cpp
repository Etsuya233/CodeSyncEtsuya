#include <iostream>
using namespace std;

int n, c;
long long arr[1005] = {0};
long long pre[1005] = {0};
long long maximum = 0;

void dfs(int loc, long long now);

int main(){
	cin >> n >> c;
	for(int i = 1; i <= n; i++){
		cin >> arr[i];
		pre[i] = pre[i - 1] + arr[i];
	}
	dfs(n, 0);
	cout << maximum;
}

void dfs(int loc, long long now){
//	cout << loc <<"   " << now << '\n';
	if(now > c) return;
	if(loc < 1){
		if(now > maximum) maximum = now;
		return;
	}
	if(now + pre[loc] > maximum){
		if(now + pre[loc] <= c){
			maximum = now + pre[loc];
			return;		
		}
	} else {
		return;
	}
	if(now + arr[loc] <= c){
		dfs(loc - 1, now + arr[loc]);
	}
	dfs(loc - 1, now);
}
