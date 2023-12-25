#include <iostream>
#include <map>
using namespace std;

int main(){
	int n;
	cin >> n;
	for(int i = 0; i < n; i++){
		map<int, int> mapa;
		int m;
		bool flag = false;
		cin >> m;
		for(int j = 0; j < m; j++){
			int num;
			cin >> num;
			int cnt = 1;
			auto ptr = mapa.find(num);
			if(ptr != mapa.end()) cnt = (*ptr).second + 1;
			if(cnt >= 3){
				flag = true;
			}
			mapa[num] = cnt;
		}
		if(flag){
			cout << "YES\n";
		} else cout << "NO\n";
	}
	return 0;
}
