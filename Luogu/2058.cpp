#include <iostream>
#include <queue>
#include <map>
#include <vector>
using namespace std;

int main(){
	int n, nowCountry = 0, ans = 0, delCnt = 0;
	cin >> n;
	map<int, int> mapa;   //First is the real loc, second is the fake loc.
	vector<queue<int> > my;
	for(int i = 0; i < n; i++){
		int t, m;
		cin >> t >> m;
		for(int j = 0; j < m; j++){
			int country;
			cin >> country;
			if(!mapa[country]){
				mapa[country] = nowCountry ++;
				queue<int> temp;
				my.push_back(temp);
				ans ++;
			}
			my[mapa[country] - delCnt].push(t);
		}
		int limit = (t - 86400)? t - 86400: 0;
		for(int j = 0; j < nowCountry - delCnt; j++){
			while(!my[j].empty()){
				if(my[j].front() <= limit){
					my[j].pop();
				} else {
					break;
				}
			}
			if(my[j].empty()){
				for(map<int, int>::iterator it = mapa.begin(); it != mapa.end(); it++){
					if(it -> second == j) {
						mapa.erase(it);
						break;
					}
				}
				my.erase(my.begin() + j);
				delCnt ++;
				ans --;
			}
		}
		cout << ans << "\n";
	}
}