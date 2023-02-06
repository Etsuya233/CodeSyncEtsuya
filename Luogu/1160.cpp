#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
	int n;
	cin >> n;
	vector<int> my;
	my.push_back(1);
	for(int i = 2; i <= n; i++){
		int a, b;
		cin >> a >> b;
		vector<int>::iterator it = find(my.begin(), my.end(), a);
		if(b){
			it ++;
		}
		my.insert(it, i);
	}
	int m;
	cin >> m;
	for(int i = 0; i < m; i++){
		int a;
		cin >> a;
		vector<int>::iterator it = find(my.begin(), my.end(), a);
		if(*it == a){
			my.erase(it, it + 1);
		}
	}
	for(vector<int>::iterator it = my.begin(); it != my.end(); it ++){
		cout << *it << " ";
	}
}