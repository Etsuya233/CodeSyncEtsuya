#include <iostream>
#include <queue>
#include <map>
#include <vector>
using namespace std;

int main(){
	int n, ans = 0, nowCountry = 0;
	cin >> n;
    map<int, int> mapa;
    vector<queue<int> > my;
	for(int i = 0; i < n; i++){
		int t, m;
		cin >> t >> m;
        if(!mapa[t]){
            queue<int> temp;
            mapa[t] = nowCountry ++;
            my.push_back(temp);
        }
        int loc = mapa[t];
		for(int j = 0; j < m; j++){
			int country;
			cin >> country;
			my[loc].push(country);
		}
		int limit = (t - 86400)? t - 86400: 0;
        
		cout << ans << "\n";
	}
}