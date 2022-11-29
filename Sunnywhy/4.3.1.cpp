#include <iostream>
#include <cstdio>
using namespace std;

void fish_entrance(int index);
void fish(int index);

int main(){
	int n;
	cin >> n;
	fish_entrance(n);
	
}

void fish_entrance(int index){
	cout << "吓得我抱起了";
	fish(index);
}

void fish(int index){
	if(index == 0){
		cout << "我的小鲤鱼";
		return;
	} else {
		cout << "抱着";
		fish(index - 1);
	}
	cout << "的我";
}
