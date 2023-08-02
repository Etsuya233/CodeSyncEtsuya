#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

typedef struct CheckPaper{
	int date, val;
} che;

int days[13] = {0};
int increment[13] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
che check[1010];
che tempa;
int n, m, k, ans = 0;
int opts[1010][1010];

bool cmpCheck(che a, che b);
void dfs(int no, int last, int money);

int main(){
	for(int i = 2; i <= 12; i++){
		days[i] = days[i - 1] + increment[i - 1];
	}
	fill(opts, opts + 1010 * 1010, -1);
	cin >> n >> m >> k;
	for(int i = 1; i <= n; i++){
		int month, day;
		cin >> month >> day >> tempa.val;
		tempa.date = days[month] + day;
		check[i] = tempa;
	}
	tempa.date = 0;
	tempa.val = 0;
	check[0] = tempa;
	sort(check + 1, check + n + 1, cmpCheck);
	dfs(1, 0, 0);
	cout << ans;
	return 0;
}

void dfs(int no, int last, int money){
	if(money > m){
		return;
	}
	if(opts[no][last] >= money) return;
	opts[no][last] = money;
	if(money > ans) ans = money;
	dfs(no + 1, last, money);
	if(check[no].date - check[last].date > k) dfs(no + 1, no, money + check[no].val);
}

bool cmpCheck(che a, che b){
	return a.date < b.date;
}
