#include <iostream>
#include <algorithm>
using namespace std;

int days[13] = {0};
int increment[13] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int check[400] = {0};
int theLastDate = 0, theFirstDate = 1000;
int ans = 0;
int suffix[400] = {0};
int n, m, k;
void dfs(int today, int money);

int main(){
	for(int i = 2; i <= 12; i++){
		days[i] = days[i - 1] + increment[i - 1];
	}
	cin >> n >> m >> k;
	for(int i = 0; i < n; i++){
		int month, day, val, doy;
		cin >> month >> day >> val;
		doy = days[month - 1] + day;
		if(check[doy] < val){
			check[doy] = val;
			theLastDate = max(theLastDate, doy);
			theFirstDate = min(theFirstDate, doy);
		}
	}
	for(int i = 365; i >= 1; i--){
		suffix[i] = suffix[i + 1] + check[i];
	}
	dfs(theFirstDate, 0);
	cout << ans;
}


void dfs(int today, int money){
	if(today > theLastDate){
		ans = max(ans, money);
		return;
	}
	for(int i = today; i <= theLastDate; i++){
		if(check[i] > 0){
			if(money + suffix[i] < ans) return;
			dfs(i + k,  money + check[i]);
		}
	}
}
