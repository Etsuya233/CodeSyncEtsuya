#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>
using namespace std;

bool cmpId(struct Student a, struct Student b);
bool cmpName(struct Student a, struct Student b);
bool cmpScore(struct Student a, struct Student b);

struct Student{
	int score;
	char id[6];
	char name[10];
};

int main(){
	while(1){
		int amount;
		cin >> amount;
		struct Student array[amount];
		int mode;
		cin >> mode;
		for(int i = 0; i < amount; i++){
			cin >> array[i].id >> array[i].name >> array[i].score;
		}
		switch(mode){
		case 1:
			sort(array, array + amount, cmpId);
			break;
		case 2:
			sort(array, array + amount, cmpName);
			break;
		case 3:
			sort(array, array + amount, cmpScore);
			break;
		}
		for(int i = 0; i < amount; i++){
			cout << array[i].id << " " << array[i].name << " " << array[i].score << "\n";
		}
	}
}

bool cmpId(struct Student a, struct Student b){
	return strcmp(a.id, b.id) > 0;
}

bool cmpName(struct Student a, struct Student b){
	return strcmp(a.name, b.name) > 0;
}

bool cmpScore(struct Student a, struct Student b){
	return a.score > b.score;
}
