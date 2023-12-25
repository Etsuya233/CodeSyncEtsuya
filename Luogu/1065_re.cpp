#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef struct Procejure{
	int no, t;
} pro;

typedef struct ProduceLine{
	int l, r;
} pl;

int n, m;
int arr[500], totalA;
pro produce[21][21];
int process[21];
int processTime[21];
vector<pl> machine[21];
pl tempa;
pl tempa1;
int res = 0;

int main(){
	//Init
	cin >> m >> n;
	totalA = m * n;
	for(int i = 1; i <= totalA; i++){
		cin >> arr[i];
	}
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; i++){
			cin >> produce[i][j].no;
		}
	}
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; i++){
			cin >> produce[i][j].t;
		}
	}
	tempa.l = 0;
	tempa.r = 0;
	tempa1.l = 0x7fffffff;
	tempa1.r = 0x7fffffff;
	for(int i = 1; i <= m; i++){
		machine[i].push_back(tempa);
		machine[i].push_back(tempa1);
	}
	//simulation
	for(int i = 1; i <= totalA; i++){
		int mno = produce[arr[i]][process[arr[i]]++].no;
		int mt = produce[arr[i]][process[arr[i]]++].t;
		//find
		int size = machine[mno].size();
		int j = 0;
		for(; j < size - 1; j++){
			if(machine[mno][j].r >= processTime[arr[i]]) break;
		}
		for(; j < size - 1; j++){
			int startT = machine[mno][j].r;
			int endT = machine[mno][j + 1].l;
			if(endT - startT <= mt){
				tempa.l = ((startT <= processTime[arr[i]])? processTime[arr[i]]: startT) + 1;
				tempa.r = tempa.l + mt;
				res = max(res, tempa.r);
				machine[mno].push_back(tempa);
				break;
			}
		}
	}
	cout << res;
	return 0;
}
