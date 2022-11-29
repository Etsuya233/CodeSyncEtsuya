#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

typedef struct tvshow{
	int start;
	int stop;
} tvshow;

bool cmpTvshow(tvshow a, tvshow b);

int main(){
	while(1){
		int amount;
		cin >> amount;
		if (amount == 0) break;
		tvshow tv[amount];
		
		for(int i = 0; i < amount; i++){
			cin >> tv[i].start >> tv[i].stop;
		}
		
		sort(tv, tv + amount, cmpTvshow);
		
		int count = 1;
		int foot = tv[0].start;
		for(int i = 1; i < amount; i++){
			if(tv[i].stop <= foot){
				foot = tv[i].start;
				count ++;
			}
		}
		
		cout << count << endl;
	}
}

bool cmpTvshow(tvshow a, tvshow b){
	if(a.start == b.start){
		if(a.stop < b.stop) return true;
		else return false;
	} else if(a.start > b.start) return true;
	else return false;
}
