#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

typedef pair<int, int> pii;
int n, k;
int arr[1000006];


int main(){
	cin >> n >> k;
	for(int i = 1; i <= n; i++){
		cin >> arr[i];
	}
	priority_queue<pii, vector<pii>, greater<pii>> minqu;
	for(int i = 1; i <= n; i++){
		while(!minqu.empty() && i - minqu.top().second >= k) minqu.pop();
		minqu.push({arr[i], i});
		if(i >= k) cout << minqu.top().first << " ";
	}
	cout << "\n";
	priority_queue<pii> maxqu;
	for(int i = 1; i <= n; i++){
		while(!maxqu.empty() && i - maxqu.top().second >= k) maxqu.pop();
		minqu.push({arr[i], i});
		if(i >= k) cout << maxqu.top().first << " ";
	}
	cout << "\n";
	return 0;
}
