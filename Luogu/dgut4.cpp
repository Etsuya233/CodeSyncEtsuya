#include <iostream>
#include <algorithm>
#include <cmath>
#include <unordered_set>
using namespace std;

int a, n, m;
int arr[22][1005] = {0};
int vis[1005];
int s[1005];

int main(){
	cin >> a >> n >> m;
	for(int i = 0; i < a; i++){
		cin >> n >> m;
		unordered_set<int> sets;
		//s
		for(int j = 1; j <= m; j++){
			cin >> s[j];
			sets.insert(s[j]);
		}
		auto setend = sets.end();
		//xi
		for(int j = 1; j <= n; j++){
			int len;
			cin >> len;
			arr[j][0] = len;
			for(int k = 1; k <= len; k++){
				cin >> arr[j][k];
			}
		}
		//hash
		map<int, int> mapa;
		bool res = false;
		for(int j = 1; j <= n - 1; j++){
			for(int k = j + 1; k <= n; k++){
				if(abs(arr[j][0] - arr[k][0]) < m) continue;
				for(int l = 1; l <= arr[j][0]; l++){
					mapa[arr[j][l]] ++;
				}
				for(int l = 1; l <= arr[k][0]; l++){
					mapa[arr[k][l]] ++;
				}
				bool okay = true;
				for(auto it = mapa.begin(); it != mapa.end(); it++){
					int now = *it;
					auto it2 = sets.find((*it).first);
					if(it2 != setend){//s存在这个元素
						if((*it).second != 1){
							okay = false;
							break;
						}
					} else {
						if((*it).second != 2){
							okay = false;
							break;
						}
					}
				}
			}
		}
		if(res) cout << "NO\n";
		else cout << "YES\n";
	}
	return 0;
}

void discreet(){
	sort(book, book + cnt);
	int reu = unique(book, book + cnt) - book;
	for(int i = 0; i < line; i++){
		arr[i] = lower_bound(book, book + reu, arr[i]) - book;
	}
}
