#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

typedef struct Point{
	int id, fre;
} po;

int cnt = 0;
po arr[100005];
set<int> cant;
int ans = 0;
int maxScore = -1;

bool cmpPoint(po a, po b);

int main(){
	int n, k;
	cin >> n >> k;
	for(int i = 0; i <= 100000; i++){
		arr[i].id = i;
	}
	for(int i = 0; i < n; i++){
		int a;
		cin >> a;
		if(arr[a].fre == 0) cnt++;
		maxScore = max(maxScore, a);
		arr[a].fre ++;
	}
	if(k == 0){
		cout << cnt;
		return 0;
	}
	sort(arr, arr + 100000, cmpPoint);
	cant.insert(arr[0].id);
	cant.insert(arr[0].id + k);
	cant.insert(arr[0].id - k);
	ans += arr[0].fre;
	for(int i = 1; i <= cnt; i++){
		if(cant.find(arr[i].id) == cant.end()){
			ans += arr[i].fre;
			cant.insert(arr[i].id);
			cant.insert(arr[i].id + k);
			cant.insert(arr[i].id - k);
		}
	}
	cout << ans;
	return 0;
}

bool cmpPoint(po a, po b){
	return a.fre > b.fre;
}
