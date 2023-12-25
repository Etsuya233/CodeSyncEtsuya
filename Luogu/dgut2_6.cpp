#include <iostream>
using namespace std;

int p;
int food[20];
int snack[20];
int n, m, k;
int flag = 1;

void dfs(int okane, int now);

int main(){
	cin >> p;
	for(int i = 0; i < p; i++){
		cin >> n >> m >> k;
		for(int j = 0; j < n; j++){
			cin >> food[j];
		}
		for(int j = 0; j < m; j++){
			cin >> snack[j];
		}
		flag = 0;
		for(int j = 0; j < n; j++){
			dfs(k - food[j], 0);
			if(flag == 1){
				cout << "YES\n";
				break;
			}
		}
  		if(flag == 0) cout << "NO\n";
	}
	return 0;
}

void dfs(int okane, int now){
	if(okane < 0) return;
	if(okane == 0) {
		flag = 1;
		return;
	}
	for(int i = now; i < m; i++){
		if(okane - snack[i] < 0) continue;
		else dfs(okane - snack[i], i + 1);
		if(flag == 1) return;
	}
	if(flag == 1) return;
}
