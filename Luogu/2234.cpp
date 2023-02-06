#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

int main(){
	set<int> my;
	int ans = 0, n;
	cin >> n;
	cin >> ans;
	my.insert(ans);
	int small = 0, big = 0;
	set<int>::iterator it;
	for(int i = 1; i < n; i++){
		int temp, cnt = 0, find = 0;
		cin >> temp;
		for(it = my.begin(); it != my.end(); it ++, cnt ++){
			small = big;
			big = *it;
			if(*it == temp){
				find = 1;
				break;
			} else if(*it > temp){
				if(cnt == 0) ans += *it - temp;
				else ans += min(big - temp, temp - small);
				find = 1;
				break;
			}
		}
		if(!find) ans += (temp - big);
		my.insert(temp);
	}
	cout << ans;
}