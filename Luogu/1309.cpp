#include <iostream>
#include <algorithm>
using namespace std;

typedef struct Competitor{
	int id, score, power;
} com;

int n, r, no;
com arr[200003];

bool cmpCompetitor(com a, com b);

int main(){
	cin >> n >> r >> no;
	for(int i = 1; i <= 2 * n; i++){
		arr[i].id = i;
		cin >> arr[i].score;
	}
	for(int i = 1; i <= 2 * n; i++){
		cin >> arr[i].power;
	}
	for(int i = 0; i < r; i++){
		stable_sort(arr + 1, arr + 2 * n + 1, cmpCompetitor);
		for(int j = 1; j <= n; j++){
			if(arr[2 * j - 1].power > arr[2 * j].power){
				arr[2 * j - 1].score ++;
			} else arr[2 * j].score ++;
		}
	}
	stable_sort(arr + 1, arr + 2 * n + 1, cmpCompetitor);
	cout << arr[no].id;

}

bool cmpCompetitor(com a, com b){
	if(a.score > b.score){
		return true;
	} else if(a.score == b.score){
		if(a.id < b.id) return true;
	}
	return false;
}