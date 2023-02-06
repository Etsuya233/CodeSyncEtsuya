#include <iostream>
#include <queue>
#include <map>
#include <vector>
using namespace std;

int main(){
	int n, ans = 0, maxCountry = 0;
	cin >> n;
	queue<int> my[100000];
	for(int i = 0; i < n; i++){
		int t, m;
		cin >> t >> m;
		for(int j = 0; j < m; j++){
			int country;
			cin >> country;
			maxCountry = (country > maxCountry)? country: maxCountry;
			if(my[country].empty()) ans ++;
			my[country].push(t);
		}
		int limit = (t - 86400)? t - 86400: 0;
		for(int j = 1; j <= maxCountry; j++){
			while(!my[j].empty()){
				if(my[j].front() <= limit){
					my[j].pop();
				} else {
					break;
				}
				if(my[j].empty()) ans --;
			}
		}
		cout << ans << "\n";
	}
}