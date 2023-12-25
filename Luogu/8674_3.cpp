#include <iostream>
#include <queue>
using namespace std;

int t[100050] = {0}, n, k, vis[100050] = {0}, ans = 0;
queue<int> my;

int main(){
	cin >> n >> k;
	my.push(0);
	vis[0] = 1;
	while(!my.empty()){
		int i = my.front();
		ans = max(ans, t[i]);
		my.pop();
		int n1 = (i + 1) % n;
		int n2 = (i + k) % n;
		if(!vis[n1]){
			vis[n1] = 1;
			t[n1] = t[i] + 1;
			my.push(n1);
		}
		if(!vis[n2]){
			vis[n2] = 1;
			t[n2] = t[i] + 1;
			my.push(n2);
		}
	}
	cout << ans;
}
