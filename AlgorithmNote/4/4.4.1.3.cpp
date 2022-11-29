#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

typedef struct interval{
	int head;
	int foot;
} interval;

bool cmpInterval(interval a, interval b);
void printInterval(interval a);

int main(){
	int amount;
	cin >> amount;
	interval storage[amount];
	
	for(int i = 0; i < amount; i++){
		cin >> storage[i].head;
		cin >> storage[i].foot;
	}
	
	sort(storage, storage + amount, cmpInterval);
	
	int front = storage[0].head;
	printInterval(storage[0]);
	for(int i = 1; i < amount; i++){
		if(storage[i].foot <= front){
			front = storage[i].head;
			printInterval(storage[i]);
		}
	}
	
}

bool cmpInterval(interval a, interval b){
	return a.head > b.head;
}

void printInterval(interval a){
	cout << "(" << a.head << "," << a.foot << ")" << endl;
}
