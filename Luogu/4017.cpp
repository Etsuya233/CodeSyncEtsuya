#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

typedef struct Node{
	short flag = 1;
	long long data = 0;
	vector<int> next;
} node;

const int MO = 80112002;
int n, m;
long long ans = 0;
node arr[5001];

long long opera(int i);

int main(){
	cin >> n >> m;
	for(int i = 0; i < m; i++){
		int a, b;
		cin >> a >> b;
		arr[b].flag = 0;
		arr[a].next.push_back(b);
	}
	for(int i = 1; i <= n; i++){
		opera(i);
	}
	for(int i = 1; i <= n; i++){
		if(arr[i].flag) {
			ans = (ans + arr[i].data) % MO;
		}
	}
	cout << ans % MO;
}

long long opera(int i){
	if(arr[i].next.empty()) {
		arr[i].data = 1;
		return 1;
	}
	if(arr[i].data > 0) return arr[i].data;
	else {
		vector<int>::iterator it = arr[i].next.begin();
		for(; it!= arr[i].next.end(); it++){
			arr[i].data = (opera(*it) + arr[i].data) % MO;
		}
		return arr[i].data;
	}
}